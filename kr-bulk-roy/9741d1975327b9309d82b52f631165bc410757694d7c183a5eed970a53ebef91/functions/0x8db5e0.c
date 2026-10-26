
undefined4 FUN_008db5e0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_2 + 0x60);
  if ((-1 < iVar1) && (iVar1 < *(int *)(param_1 + 300))) {
    iVar1 = iVar1 * 0xfc + *(int *)(param_1 + 0x130);
    uVar2 = (**(code **)(param_2 + 0x28))(param_2,0);
    *(undefined4 *)(iVar1 + 0xd0) = uVar2;
    *(undefined4 *)(iVar1 + 0xb4) = uVar2;
  }
  return 0;
}

