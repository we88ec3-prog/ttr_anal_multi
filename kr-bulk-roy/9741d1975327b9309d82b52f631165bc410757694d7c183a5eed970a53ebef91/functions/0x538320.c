
uint FUN_00538320(int param_1)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (in_EAX != 0) {
    uVar1 = FUN_0072e360();
    FUN_00537340(param_1,uVar1);
    iVar2 = FUN_0072e2e0("BRANCH");
    uVar3 = 0;
    if (iVar2 != 0) {
      iVar2 = FUN_0072e360();
      while( true ) {
        if (iVar2 == 0) {
          return 1;
        }
        uVar3 = FUN_00537a40(iVar2,param_1 + 0x10);
        if ((char)uVar3 == '\0') break;
        iVar2 = FUN_0072e3c0();
      }
    }
  }
  return uVar3 & 0xffffff00;
}

