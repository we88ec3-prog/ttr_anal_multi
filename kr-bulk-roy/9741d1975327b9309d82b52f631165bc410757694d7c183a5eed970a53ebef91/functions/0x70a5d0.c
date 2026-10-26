
undefined4 FUN_0070a5d0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_006f6210(param_1);
  iVar2 = FUN_0070a230(uVar1,"cpath");
  if (iVar2 != 0) {
    uVar1 = FUN_0070a560();
    iVar3 = FUN_0070a0a0(iVar2,uVar1);
    if (iVar3 != 0) {
      FUN_0070a470(iVar2);
    }
  }
  return 1;
}

