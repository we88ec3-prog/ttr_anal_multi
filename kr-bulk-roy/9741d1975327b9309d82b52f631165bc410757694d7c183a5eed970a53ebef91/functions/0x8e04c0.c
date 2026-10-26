
void FUN_008e04c0(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *in_EDX;
  undefined4 *unaff_ESI;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(*(int *)(in_EAX + 0x80) + 0x30) != 0) {
    puVar1 = *(undefined4 **)(*(int *)(in_EAX + 0x80) + 0x30);
    (**(code **)*puVar1)(puVar1[1]);
    *in_EDX = local_c;
    *unaff_ESI = local_8;
    return;
  }
  FUN_008dde20();
  return;
}

