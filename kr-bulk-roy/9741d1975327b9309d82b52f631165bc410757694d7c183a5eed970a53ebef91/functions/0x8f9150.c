
undefined4 FUN_008f9150(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0x5c);
  *(uint *)(param_1 + 0x28) = (uint)*(ushort *)(param_2 + 0x44);
  iVar2 = FUN_008b8c70(param_2,0x756e6963);
  if (iVar2 == 0) {
    FUN_008f8a20();
    FUN_008f8d20(param_2);
    FUN_008f90d0(param_1,param_2);
  }
  FUN_008ba740(param_2,uVar1);
  return 0;
}

