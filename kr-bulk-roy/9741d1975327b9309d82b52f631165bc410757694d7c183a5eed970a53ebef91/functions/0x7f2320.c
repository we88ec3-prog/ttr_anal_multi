
void FUN_007f2320(undefined4 param_1,float param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if ((param_2 <= *(float *)(in_ECX + 0x70)) && (0.0 <= param_2)) {
    iVar1 = *(int *)(in_ECX + 0x88);
    *(undefined4 *)(in_ECX + 0x7c) = 1;
    FUN_0077ea00();
    *(undefined4 *)(iVar1 + 0xc0) = 0;
    iVar1 = **(int **)(in_ECX + 0x88);
    uVar2 = FUN_008fed10();
    (**(code **)(iVar1 + 0x1c))(uVar2);
    FUN_00780150(*(int *)(in_ECX + 0x88),*(undefined4 *)(*(int *)(in_ECX + 0x88) + 0x30));
    return;
  }
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  return;
}

