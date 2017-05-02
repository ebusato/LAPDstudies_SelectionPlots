
TH1F* MakePlot(TChain* ch, TCut cut, TString hName, int color)
{
  TH1F* hE = new TH1F(hName.Data(),hName.Data(),200,0,1200);
  TString s("E");
  s+=">>";
  s+=hName;
  ch->Draw(s.Data(), cut, "goff");
  hE->GetXaxis()->SetTitle("E [keV]");
  hE->GetYaxis()->SetTitle("Entries [a. u.]");
  hE->GetYaxis()->SetTitleSize(0.055);
  hE->GetXaxis()->SetTitleSize(0.055);
  hE->GetYaxis()->SetTitleOffset(1.6);
  hE->GetXaxis()->SetTitleOffset(1.35);
  hE->GetYaxis()->SetLabelSize(0.05);
  hE->GetXaxis()->SetLabelSize(0.05);
  hE->GetZaxis()->SetLabelSize(0.04);
  hE->SetFillStyle(3002);
  hE->SetFillColor(color);
  hE->Scale(1/hE->Integral());
  return hE;
}

void SelectionPlots()
{
  TChain* ch0 = new TChain("tree");
  ch0->Add("/media/ebusato/d86d79cb-a880-435d-8620-d4f4c8a1149f/DataBackup/godaq_rootfiles/analysis_v2.14-calibG2/run110.root");
  TCut cut0 = "Sat == 0";
  TH1F* hE_NoSel = MakePlot(ch0, cut0, "hE_NoSel", kGreen-2);

  TChain* ch1 = new TChain("tree");
  ch1->Add("/home/ebusato/godaq/v2.10/run110LOR.root");
  TCut cut1 = "NoLORs == 1";
  TH1F* hE_Sel = MakePlot(ch1, cut1, "hE_Sel", kGreen-2);

  TCanvas* c1 = new TCanvas("c1","c1");
  c1->SetGridx(1);
  c1->SetGridy(1);
  hE_NoSel->Draw();	
  PutText(0.5, 0.81, kBlack, "LAPD", 0.05);
  PutText(0.5, 0.75, kBlack, "Protons 65 MeV, I = 5 nA", 0.05);
  PutText(0.5, 0.69, kBlack, "Target PMMA 5 #times 5 cm", 0.05);
  c1->SaveAs("c1.png");

  TCanvas* c2 = new TCanvas("c2","c2");
  c2->SetGridx(1);
  c2->SetGridy(1);
  hE_Sel->Draw();	
  PutText(0.55, 0.81, kBlack, "LAPD", 0.05);
  PutText(0.55, 0.75, kBlack, "Protons 65 MeV, I = 5 nA", 0.05);
  PutText(0.55, 0.69, kBlack, "Target PMMA 5 #times 5 cm", 0.05);
  c2->SaveAs("c2.png");
}
