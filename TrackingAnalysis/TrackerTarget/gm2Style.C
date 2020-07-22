//
// g-2 Style, based on a style file from ATLAS
//

#include <iostream>

#include "gm2Style.h"

#include "TROOT.h"

void SetGm2Style ()
{
  static TStyle* Gm2Style = 0;
  std::cout << "\nApplying g-2 style settings...\n" << std::endl ;
  if ( Gm2Style==0 ) Gm2Style = gm2Style();
  gROOT->SetStyle("gm2");
  gROOT->ForceStyle();
}

TStyle* gm2Style() 
{
  TStyle *gm2Style = new TStyle("gm2","gm2 style");

  // use plain black on white colors
  Int_t icol=0; // WHITE
  gm2Style->SetFrameBorderMode(icol);
  gm2Style->SetFrameFillColor(icol);
  gm2Style->SetCanvasBorderMode(icol);
  gm2Style->SetCanvasColor(icol);
  gm2Style->SetPadBorderMode(icol);
  gm2Style->SetPadColor(icol);
  gm2Style->SetStatColor(icol);
  gm2Style->SetStatBorderSize(1);

  // set the paper & margin sizes
  gm2Style->SetPaperSize(20,26);

  // set margin sizes
  gm2Style->SetPadTopMargin(0.05);
  gm2Style->SetPadRightMargin(0.05);
  gm2Style->SetPadBottomMargin(0.16);
  gm2Style->SetPadLeftMargin(0.16);

  // set title offsets (for axis label)
  gm2Style->SetTitleXOffset(1.4);
  gm2Style->SetTitleYOffset(1.4);

  // use large fonts
  //Int_t font=72; // Helvetica italics
  Int_t font=42; // Helvetica
  Double_t tsize=0.05;
  gm2Style->SetTextFont(font);

  gm2Style->SetLegendFont(font);
  gm2Style->SetLegendTextSize(0.04);

  gm2Style->SetTextSize(tsize);
  gm2Style->SetLabelFont(font,"x");
  gm2Style->SetTitleFont(font,"x");
  gm2Style->SetLabelFont(font,"y");
  gm2Style->SetTitleFont(font,"y");
  gm2Style->SetLabelFont(font,"z");
  gm2Style->SetTitleFont(font,"z");
  
  gm2Style->SetLabelSize(tsize,"x");
  gm2Style->SetTitleSize(tsize,"x");
  gm2Style->SetLabelSize(tsize,"y");
  gm2Style->SetTitleSize(tsize,"y");
  gm2Style->SetLabelSize(tsize,"z");
  gm2Style->SetTitleSize(tsize,"z");

  // use bold lines and markers
  gm2Style->SetMarkerStyle(20);
  gm2Style->SetMarkerSize(1.2);
  gm2Style->SetHistLineWidth(2.);
  gm2Style->SetLineStyleString(2,"[12 12]"); // postscript dashes

  // get rid of X error bars (as recommended in ATLAS figure guidelines)
  gm2Style->SetErrorX(0.0001);
  // get rid of error bar caps
  gm2Style->SetEndErrorSize(0.);

  //do not display any of the standard histogram decorations
  gm2Style->SetOptTitle(0);
  //gm2Style->SetOptStat(0);
  //gm2Style->SetOptFit(0);

  // put tick marks on top and RHS of plots
  gm2Style->SetPadTickX(1);
  gm2Style->SetPadTickY(1);

  return gm2Style;

}

