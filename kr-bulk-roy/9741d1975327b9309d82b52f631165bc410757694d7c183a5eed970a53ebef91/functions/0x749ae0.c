
void FUN_00749ae0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 *puVar1;
  
  if (param_1[0x18] != 0) {
    puVar1 = (undefined4 *)FUN_00748830(param_1[0x18]);
    param_2 = *puVar1;
    param_3 = puVar1[1];
    param_4 = puVar1[2];
    param_5 = puVar1[3];
  }
  (**(code **)(*param_1 + 0xbc))(param_2,param_3,param_4,param_5);
  return;
}

