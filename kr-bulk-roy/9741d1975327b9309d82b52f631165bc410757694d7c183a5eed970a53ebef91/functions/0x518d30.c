
void FUN_00518d30(void)

{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00820120();
  *puVar1 = DAT_00fe3014;
  puVar1[1] = DAT_00fe3014;
  puVar1[2] = DAT_00fe3014;
  *(undefined2 *)(puVar1 + 6) = 0;
  if (puVar1 + 3 != (undefined4 *)0x0) {
    puVar1[3] = *in_EAX;
    puVar1[4] = in_EAX[1];
    *(undefined2 *)(puVar1 + 5) = *(undefined2 *)(in_EAX + 2);
  }
  return;
}

