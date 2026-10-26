
undefined4 FUN_00737ce0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)FUN_00714770();
  if (piVar1 == (int *)0x0) {
    return 0x8876086a;
  }
  uVar2 = (**(code **)(*piVar1 + 0x38))();
  uVar3 = (**(code **)(*piVar1 + 0x2c))();
  uVar2 = D3DXGetImageInfoFromFileInMemory(uVar2,uVar3,param_1);
  (**(code **)(*piVar1 + 4))();
  return uVar2;
}

