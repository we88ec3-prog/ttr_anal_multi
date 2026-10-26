
undefined4 FUN_004b34f0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  uVar1 = *(undefined2 *)(param_1 + 2);
  iVar2 = FUN_00404ba0();
  *(undefined2 *)(iVar2 + 0x6860) = uVar1;
  return 0;
}

