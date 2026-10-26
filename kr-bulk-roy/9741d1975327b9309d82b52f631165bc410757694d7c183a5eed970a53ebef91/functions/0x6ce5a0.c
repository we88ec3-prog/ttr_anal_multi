
void FUN_006ce5a0(int param_1)

{
  int unaff_ESI;
  
  if (param_1 != 0) {
    FUN_006ce610(param_1);
    FUN_00402a70("Custom",6);
    FUN_00403040(param_1,0,0xffffffff);
    return;
  }
  FUN_006ce610(unaff_ESI + 0x14);
  FUN_00402a70("Custom",6);
  FUN_00402a70("Empty",5);
  return;
}

