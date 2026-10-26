
undefined4 FUN_008e0630(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 0x290);
  if (*(int *)(iVar2 + 0x488) == 0) {
    return 0xa3;
  }
  uVar3 = (**(code **)(*(int *)(iVar2 + 0xb8c) + 4))
                    (*(undefined4 *)(iVar1 + 100),param_1,*(undefined4 *)(iVar2 + 0xc),FUN_008e0610,
                     0,iVar1);
  return uVar3;
}

