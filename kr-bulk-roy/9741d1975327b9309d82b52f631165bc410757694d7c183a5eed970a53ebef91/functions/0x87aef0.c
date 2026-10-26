
undefined4
FUN_0087aef0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = *(undefined4 *)(param_5 + 0x44);
  uVar2 = *(undefined4 *)(param_5 + 0x48);
  uVar3 = *(undefined4 *)(param_5 + 0x4c);
  *param_3 = *(undefined4 *)(param_5 + 0x40);
  param_3[1] = uVar1;
  param_3[2] = uVar2;
  param_3[3] = uVar3;
  return 1;
}

