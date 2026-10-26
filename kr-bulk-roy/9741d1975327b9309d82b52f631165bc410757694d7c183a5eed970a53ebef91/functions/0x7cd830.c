
void FUN_007cd830(float param_1)

{
  int iVar1;
  float fVar2;
  int in_EAX;
  undefined4 uVar3;
  
  fVar2 = param_1 * 30.0 + *(float *)(in_EAX + 0x38);
  *(float *)(in_EAX + 0x38) = fVar2;
  if ((*(float *)(in_EAX + 0x34) < fVar2) && (*(int *)(in_EAX + 0x68) == 0)) {
    *(undefined4 *)(in_EAX + 0x38) = 0;
  }
  iVar1 = **(int **)(in_EAX + 0x20);
  uVar3 = FUN_008fed10();
  (**(code **)(iVar1 + 0x1c))(uVar3);
  FUN_00780150(*(int *)(in_EAX + 0x20),*(undefined4 *)(*(int *)(in_EAX + 0x20) + 0x30));
  return;
}

