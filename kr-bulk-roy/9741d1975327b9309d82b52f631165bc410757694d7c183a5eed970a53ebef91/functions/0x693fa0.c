
void FUN_00693fa0(void)

{
  int iVar1;
  int in_EAX;
  undefined4 unaff_ESI;
  
  if (*(int *)(in_EAX + 0xb0) == 0) {
    FUN_006940c0();
  }
  else if (*(int *)(in_EAX + 0xb0) == 1) {
    FUN_00694750(in_EAX);
  }
  *(undefined4 *)(in_EAX + 0xb4) = unaff_ESI;
  *(undefined4 *)(*(int *)(in_EAX + 0x80) + 0x194) = unaff_ESI;
  iVar1 = *(int *)(in_EAX + 0xac);
  *(undefined4 *)(iVar1 + 0xe0) = *(undefined4 *)(in_EAX + 0xb4);
  *(undefined4 *)(iVar1 + 0xdc) = 2;
  FUN_0068b260(*(undefined4 *)(in_EAX + 0xac));
  return;
}

