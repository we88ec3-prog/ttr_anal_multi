
undefined4
FUN_00737c50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
            undefined4 param_13)

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
  uVar2 = D3DXCreateTextureFromFileInMemoryEx
                    (param_1,uVar2,uVar3,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                     param_9,param_10,param_11,param_12,param_13);
  (**(code **)(*piVar1 + 4))();
  return uVar2;
}

