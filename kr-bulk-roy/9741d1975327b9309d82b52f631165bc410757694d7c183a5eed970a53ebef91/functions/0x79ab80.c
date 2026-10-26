
void FUN_0079ab80(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1[5] != 0) {
    FUN_0077f030(param_2,param_3,param_4);
    FUN_00780610();
    FUN_0077efc0();
    FUN_0077ef50(0x3dcccccd,0x3dcccccd,0x3dcccccd);
    FUN_00780150(param_1[5],*(undefined4 *)(param_1[5] + 0x30));
    (**(code **)(*(int *)param_1[5] + 0x28))(*param_1);
  }
  return;
}

