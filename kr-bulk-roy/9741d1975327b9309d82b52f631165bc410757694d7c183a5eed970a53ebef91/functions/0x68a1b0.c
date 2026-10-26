
void FUN_0068a1b0(int *param_1)

{
  float in_XMM1_Da;
  
  param_1[0x25] = 1;
  if (in_XMM1_Da == 0.0) {
    param_1[0x27] = param_1[0x29];
  }
  else {
    param_1[0x27] = (int)in_XMM1_Da;
  }
  param_1[0x2c] = 0;
  param_1[0x24] = 0;
  *(undefined1 *)(param_1 + 0x36) = 0;
  FUN_0068a440(param_1);
  (**(code **)(*(int *)param_1[0x20] + 0x94))(1);
  (**(code **)(*(int *)param_1[0x21] + 0x94))(0);
  (**(code **)(*(int *)param_1[0x22] + 0x94))(0);
  (**(code **)(*(int *)param_1[0x23] + 0x94))(0);
  if (param_1[0x18] != 0) {
    FUN_0074a010(param_1);
  }
  (**(code **)(*param_1 + 0xd0))();
  return;
}

