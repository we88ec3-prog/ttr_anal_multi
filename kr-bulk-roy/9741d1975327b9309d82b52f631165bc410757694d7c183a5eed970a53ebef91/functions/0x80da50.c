
undefined4 FUN_0080da50(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)FUN_0080cfb0();
  if (piVar2 != (int *)0x0) {
    iVar1 = *param_1;
    uVar3 = (**(code **)(*piVar2 + 0x14))();
    uVar3 = (**(code **)(*piVar2 + 0x10))(uVar3);
    uVar3 = (**(code **)(*piVar2 + 8))(uVar3);
    uVar3 = (**(code **)(*piVar2 + 0xc))(uVar3);
    uVar3 = (**(code **)(iVar1 + 0x10))(uVar3);
    (**(code **)*piVar2)(1);
    return uVar3;
  }
  return 0;
}

