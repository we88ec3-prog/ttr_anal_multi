
void FUN_005471b0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  iVar1 = DAT_00fe48d0;
  if (DAT_00fe48d0 + 5U < 0x1001) {
    *(undefined4 *)(&DAT_00fe38d0 + DAT_00fe48d0) = *in_ECX;
    (&DAT_00fe38d4)[iVar1] = *(undefined1 *)(in_ECX + 1);
    DAT_00fe48d0 = DAT_00fe48d0 + 5;
  }
  return;
}

