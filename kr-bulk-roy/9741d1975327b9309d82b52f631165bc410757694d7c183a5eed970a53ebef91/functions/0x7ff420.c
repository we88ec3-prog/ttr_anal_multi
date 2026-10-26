
void FUN_007ff420(undefined4 *param_1,undefined4 *param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x44) != 0) {
    FUN_007fed70();
  }
  *param_1 = *(undefined4 *)(in_ECX + 0x34);
  param_1[1] = *(undefined4 *)(in_ECX + 0x38);
  param_1[2] = *(undefined4 *)(in_ECX + 0x3c);
  *param_2 = *(undefined4 *)(in_ECX + 0x40);
  return;
}

