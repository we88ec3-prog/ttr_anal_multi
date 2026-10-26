
void FUN_005d1940(int param_1)

{
  int iVar1;
  
  iVar1 = 41000;
  do {
    if (param_1 == iVar1) {
      FUN_005d2320();
    }
    iVar1 = iVar1 + 10000;
  } while (iVar1 < 81000);
  if (param_1 == 20000) {
    FUN_0040e1f0();
  }
  if (param_1 == 0x4e22) {
    FUN_0040e2b0();
  }
  if (param_1 == 0x2bc0) {
    FUN_0040e070();
  }
  return;
}

