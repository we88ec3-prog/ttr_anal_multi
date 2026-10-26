
void FUN_007296f0(FILE *param_1)

{
  uint in_EAX;
  int iVar1;
  
  iVar1 = 4;
  do {
    FID_conflict__fputc(in_EAX & 0xff,param_1);
    in_EAX = in_EAX >> 8;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

