
void FUN_004cab30(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xac) != 0) {
    (**(code **)*DAT_00fba838)
              (*(undefined4 *)(in_ECX + 0xa0),*(undefined4 *)(in_ECX + 0xa4),in_ECX + 0xa8,0);
    *(undefined4 *)(in_ECX + 0xac) = 0;
  }
  return;
}

