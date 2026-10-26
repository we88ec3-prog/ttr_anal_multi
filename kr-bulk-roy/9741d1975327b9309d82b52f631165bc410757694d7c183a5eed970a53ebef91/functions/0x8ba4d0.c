
void FUN_008ba4d0(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  
  if (*(code **)(param_2 + 8) != (code *)0x0) {
    (**(code **)(param_2 + 8))(param_2);
  }
  pcVar1 = *(code **)(*(int *)(param_3 + 0xc) + 0x3c);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_2);
  }
  FUN_008b9f80(param_1,*(undefined4 *)(param_2 + 0x28));
  *(undefined4 *)(param_2 + 0x28) = 0;
  FUN_008b9f80(param_1,param_2);
  return;
}

