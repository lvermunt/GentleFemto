/*
 * MakeHistosGreat.cxx
 *
 *  Created on: Feb 8, 2019
 *      Author: schmollweger
 */

#include "MakeHistosGreat.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TGaxis.h"
#include "TLatex.h"
#include "TLegend.h"
std::vector<int> fFillColors = { kGray + 1, kRed - 10, kBlue - 9, kGreen - 8,
    kMagenta - 9, kOrange - 9, kCyan - 8, kYellow - 7 };
std::vector<int> fColors = { kBlack, kRed + 1, kBlue + 2, kGreen + 3, kMagenta
    + 1, kOrange - 1, kCyan + 2, kYellow + 2, kBlue + 3 };
std::vector<int> fMarkers = { kFullCircle, kFullSquare, kOpenCircle,
    kOpenSquare, kOpenDiamond, kOpenCross, kFullCross, kFullDiamond, kFullStar,
    kOpenStar };

MakeHistosGreat::MakeHistosGreat()
    : fTightMargin(false) {
  // TODO Auto-generated constructor stub

}

MakeHistosGreat::~MakeHistosGreat() {
  // TODO Auto-generated destructor stub
}

void MakeHistosGreat::FormatHistogram(TH1* hist, unsigned int marker,
                                      unsigned int color, float size) {
  hist->GetXaxis()->SetLabelSize(0.045);
  hist->GetXaxis()->SetLabelOffset(0.01);
  hist->GetYaxis()->SetLabelSize(0.045);
  hist->GetYaxis()->SetLabelOffset(0.01);

  hist->GetXaxis()->SetTitleSize(0.05);
  hist->GetXaxis()->SetTitleOffset(1.2);
  hist->GetYaxis()->SetTitleSize(0.05);
  hist->GetYaxis()->SetTitleOffset(1.25);

  hist->SetMarkerStyle(fMarkers[marker]);
  hist->SetMarkerColor(fColors[color]);
  hist->SetMarkerSize(size);
  hist->SetLineColor(fColors[color]);
  hist->SetLineWidth(2);
}

void MakeHistosGreat::FormatSmallHistogram(TH1* hist, unsigned int marker,
                                           unsigned int color, float size) {
  hist->GetXaxis()->SetLabelSize(0.08);
  hist->GetXaxis()->SetLabelOffset(0.01);
  hist->GetYaxis()->SetLabelSize(0.08);
  hist->GetYaxis()->SetLabelOffset(0.01);

  hist->GetXaxis()->SetTitleSize(0.08);
  hist->GetXaxis()->SetTitleOffset(0.9);
  hist->GetYaxis()->SetTitleSize(0.08);
  hist->GetYaxis()->SetTitleOffset(1.0);

  hist->SetMarkerStyle(fMarkers[marker]);
  hist->SetMarkerColor(fColors[color]);
  hist->SetMarkerSize(size);
  hist->SetLineColor(fColors[color]);
  hist->SetLineWidth(2);
}

void MakeHistosGreat::FormatHistogram(TH2 *histo) {
  histo->GetXaxis()->SetLabelSize(0.045);
  histo->GetXaxis()->SetLabelOffset(0.01);
  histo->GetYaxis()->SetLabelSize(0.045);
  histo->GetYaxis()->SetLabelOffset(0.01);

  histo->GetXaxis()->SetTitleSize(0.05);
  histo->GetXaxis()->SetTitleOffset(1.2);
  histo->GetYaxis()->SetTitleSize(0.05);
  histo->GetYaxis()->SetTitleOffset(1.25);

//  histo->SetMarkerStyle(fMarkers[marker]);
//  histo->SetMarkerColor(fColors[color]);
//  histo->SetLineColor(fColors[color]);
}

void MakeHistosGreat::DrawAndStore(std::vector<TH1*> hist, const char* outname,
                                   const char* drawOption) {
  auto c1 = new TCanvas(Form("%s", outname), Form("%s", outname));
  if (fTightMargin) {
    c1->SetTopMargin(0.02);
    c1->SetRightMargin(0.01);
  }
  c1->cd();
  TString DrawOpt = Form("%s", drawOption);
  bool oneTime = false;
  for (auto it : hist) {
    it->Draw(DrawOpt.Data());
    if (!oneTime) {
      oneTime = true;
      DrawOpt += "same";
    }
  }
  c1->SaveAs(Form("%s.pdf", outname));
  delete c1;
  return;
}

void MakeHistosGreat::DrawOnPad(std::vector<TH1*> hist, TPad* TPain,
                                const char* drawOption) {
  TPain->cd();
  TString DrawOpt = Form("%s", drawOption);
  bool oneTime = false;
  for (auto it : hist) {
    it->Draw(DrawOpt.Data());
    if (!oneTime) {
      oneTime = true;
      DrawOpt += "same";
    }
  }
  return;
}

void MakeHistosGreat::DrawLogYAndStore(std::vector<TH1*> hist,
                                       const char* outname,
                                       const char* drawOption) {
  auto c1 = new TCanvas(Form("%s", outname), Form("%s", outname));
  if (fTightMargin) {
    c1->SetTopMargin(0.02);
    c1->SetRightMargin(0.01);
  }
  c1->cd();
  c1->SetLogy();
  TString DrawOpt = Form("%s", drawOption);
  bool oneTime = false;
  for (auto it : hist) {
    it->Draw(DrawOpt.Data());
    if (!oneTime) {
      oneTime = true;
      DrawOpt += "same";
    }
  }
  c1->SaveAs(Form("%s.pdf", outname));
  delete c1;
  return;
}

void MakeHistosGreat::DrawAndStore(std::vector<TH2*> hist, const char* outname,
                                   const char* drawOption) {
  auto c1 = new TCanvas(Form("%s", outname), Form("%s", outname));
  if (fTightMargin) {
    c1->SetTopMargin(0.02);
    c1->SetRightMargin(0.01);
  }
  c1->cd();
  TString DrawOpt = Form("%s", drawOption);
  bool oneTime = false;
  for (auto it : hist) {
    it->Draw(DrawOpt.Data());
    if (!oneTime) {
      oneTime = true;
      DrawOpt += "same";
    }
  }
  c1->SaveAs(Form("%s.pdf", outname));
  delete c1;
  return;
}

void MakeHistosGreat::DrawLogZAndStore(std::vector<TH2*> hist,
                                       const char* outname,
                                       const char* drawOption) {
  auto c1 = new TCanvas(Form("%s", outname), Form("%s", outname));
  if (fTightMargin) {
    c1->SetTopMargin(0.02);
    c1->SetRightMargin(0.01);
  }
  c1->cd();
  c1->SetLogz();
  TString DrawOpt = Form("%s", drawOption);
  bool oneTime = false;
  for (auto it : hist) {
    it->Draw(DrawOpt.Data());
    if (!oneTime) {
      oneTime = true;
      DrawOpt += "same";
    }
  }
  c1->SaveAs(Form("%s.pdf", outname));
  delete c1;
  return;
}

void MakeHistosGreat::SetStyle(bool title) {
  const int NCont = 255;
  gStyle->Reset("Plain");
  gStyle->SetNumberContours(NCont);
  gStyle->SetOptTitle(title);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetOptStat(0);
  gStyle->SetCanvasColor(10);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetFrameLineWidth(1);
  gStyle->SetFrameFillColor(kWhite);
  gStyle->SetPadColor(10);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetHistLineWidth(1);
  gStyle->SetHistLineColor(kRed);
  gStyle->SetFuncWidth(2);
  gStyle->SetFuncColor(kGreen);
  gStyle->SetLineWidth(2);
  gStyle->SetLabelSize(0.045, "xyz");
  gStyle->SetLabelOffset(0.01, "y");
  gStyle->SetLabelOffset(0.01, "x");
  gStyle->SetLabelColor(kBlack, "xyz");
  gStyle->SetTitleSize(0.05, "xyz");
  gStyle->SetTitleOffset(1.25, "y");
  gStyle->SetTitleOffset(1.2, "x");
  gStyle->SetTitleFillColor(kWhite);
  gStyle->SetTextSizePixels(26);
  gStyle->SetTextFont(42);
  gStyle->SetLegendBorderSize(0);
  gStyle->SetLegendFillColor(kWhite);
  gStyle->SetLegendFont(42);
  gStyle->SetLegendBorderSize(0);
  gStyle->SetPalette(kBird);
//  TGaxis::SetMaxDigits(8);
}

void MakeHistosGreat::DrawLatexLabel(float pTMin, float pTMax,
                                     ForgivingFitter* fit, TPad* pad,
                                     const char* part, float xPos, float yPos) {
  float signal = (float) fit->GetSignalCounts();
  float background = (float) fit->GetBackgroundCounts();
  float meanMass = fit->GetMeanMass();
  float meanWidthActual = fit->GetMeanWidth();
  pad->cd();
  TLatex Label;
  Label.SetNDC(kTRUE);
  Label.SetTextSize(gStyle->GetTextSize() * 1.25);
  Label.DrawLatex(
      gPad->GetUxmax() - xPos,
      gPad->GetUymax() - yPos,
      Form("#splitline{#splitline{#splitline{#splitline"
           "{%.2f < #it{p}_{T} < %.2f GeV/#it{c}}"
           "{%s: %.0f}}"
           "{#LT #it{M} #GT = %.1f MeV/#it{c}^{2}}}"
           "{#sigma= %.1f MeV/#it{c}^{2}}}"
           "{Purity = %.1f %%}",
           pTMin, pTMax, part, signal, meanMass * 1000.f,
           meanWidthActual * 1000.f, signal / (signal + background) * 100.f));
}

void MakeHistosGreat::DrawPerformance(ForgivingFitter* fit, TPad* pad,
                                      const char* part, float xPos, float yPos,
                                      float pTmin, float pTmax) {
  float signal = (float) fit->GetSignalCounts();
  float background = (float) fit->GetBackgroundCounts();
  pad->cd();
  const float offset = 0.06;
  float counter = 0;
  TLatex Label;
  Label.SetNDC(kTRUE);
  Label.SetTextSize(gStyle->GetTextSize() * 0.9);
  Label.DrawLatex(xPos, yPos - offset * counter++, "#bf{ALICE Performance}");
  Label.DrawLatex(xPos, yPos - offset * counter++, "pp #sqrt{s} = 13 TeV");
  Label.DrawLatex(xPos, yPos - offset * counter++, "High Mult. (0-0.072% INEL)");
  if (pTmin > 0 && pTmax > 0) {
    Label.DrawLatex(xPos, yPos - offset * counter++,
                    Form("%.1f < #it{p}_{T} < %.1f GeV/#it{c}", pTmin, pTmax));
  }
  Label.DrawLatex(xPos, yPos - offset * counter++,
                  Form("%s: %.0f", part, signal));
  Label.DrawLatex(
      xPos, yPos - offset * counter++,
      Form("Purity = %.1f %%", signal / (signal + background) * 100.f));
}

void MakeHistosGreat::DrawPublication(ForgivingFitter* fit, TPad* pad,
                                      const char* part, float xPos, float yPos,
                                      float pTmin, float pTmax) {
  TH1F* hist = nullptr;
  if(pad->GetListOfPrimitives()->At(0)) {
    hist = (TH1F*)pad->GetListOfPrimitives()->At(0);
  }

  TString partString = TString::Format("%s", part);
  float signal = (float) fit->GetSignalCounts();
  float background = (float) fit->GetBackgroundCounts();
  pad->cd();
  const float offset = 0.065;
  float counter = 0;
  TLatex Label;
  Label.SetNDC(kTRUE);
  Label.SetTextSize(gStyle->GetTextSize() * 0.9);
  Label.DrawLatex(xPos, yPos - offset * counter++, "ALICE pp #sqrt{#it{s}} = 13 TeV");
  Label.DrawLatex(xPos, yPos - offset * counter++, "High-mult. (0#kern[-0.95]{ }#minus#kern[-0.05]{ }0.072#kern[-0.9]{ }% INEL#kern[-0.5]{ }>#kern[-0.5]{ }0)");
  if (pTmin > 0 && pTmax > 0) {
    Label.DrawLatex(xPos, yPos - offset * counter++,
                    Form("%.1f < #it{p}_{T} < %.1f GeV/#it{c}", pTmin, pTmax));
  }
  if(partString == TString("#Sigma^{0} + #bar{#Sigma^{0}}")) {
    Label.DrawLatex(xPos, yPos - offset * counter++, "#Sigma^{0} #rightarrow #Lambda#gamma, #bar{#Sigma^{0}} #rightarrow #bar{#Lambda}#gamma");
  } else if(partString == TString("#bar{#Sigma^{0}}")) {
    Label.DrawLatex(xPos, yPos - offset * counter++, "#bar{#Sigma^{0}} #rightarrow #bar{#Lambda}#gamma");
  } else if(partString == TString("#Sigma^{0}")) {
    Label.DrawLatex(xPos, yPos - offset * counter++, "#Sigma^{0} #rightarrow #Lambda#gamma");
  }
  auto leg = new TLegend(xPos - 0.005, yPos - offset * (counter - 0.75), xPos + 0.2, yPos - offset * (counter + 2));
  leg->SetBorderSize(0);
  leg->SetTextFont(42);
  leg->SetTextSize(gStyle->GetTextSize() * 0.9);
  leg->AddEntry(hist, "Data", "P");
  leg->AddEntry(fit->GetFullFitFunction(), "Total fit", "l");
  leg->AddEntry(fit->GetBackgroundFunction(), "Background", "l");
  leg->Draw("same");
}

void MakeHistosGreat::DrawLine(TPad* pad, float xMin, float xMax, float yMin, float yMax, int color) {
  TLine one;
  one.SetLineColor(color);
  one.SetLineWidth(2);
  one.SetLineStyle(3);
  pad->cd();
  one.DrawLine(xMin,yMin,xMax,yMax);
}
