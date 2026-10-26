
void FUN_004cff70(void)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)FUN_008ff870();
  if (0.01 < (float)fVar1) {
    if (*(int *)(in_ECX + 0xac) != 0) {
      (**(code **)*DAT_00fba838)
                (*(undefined4 *)(in_ECX + 0xa0),*(undefined4 *)(in_ECX + 0xa4),in_ECX + 0xa8,0);
      *(undefined4 *)(in_ECX + 0xac) = 0;
    }
    fVar1 = (float10)FUN_008ff0a0();
    *(float *)(in_ECX + 0xa8) =
         (float)fVar1 * *(float *)(in_ECX + 0x114) + *(float *)(in_ECX + 0xa8);
    return;
  }
  if (*(int *)(in_ECX + 0xac) != 0) {
    (**(code **)*DAT_00fba838)
              (*(undefined4 *)(in_ECX + 0xa0),*(undefined4 *)(in_ECX + 0xa4),in_ECX + 0xa8,0);
    *(undefined4 *)(in_ECX + 0xac) = 0;
  }
  return;
}

