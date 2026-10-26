
void FUN_005541e0(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0xc) != 0) {
    if (*(int *)(in_EAX + 8) == 0) {
      FUN_00554160();
      goto LAB_00554206;
    }
    if (*(int *)(in_EAX + 0xc) != 0) goto LAB_00554206;
  }
  if (*(int *)(in_EAX + 8) != 0) {
    FUN_005541a0();
  }
LAB_00554206:
  if (0 < *(int *)(in_EAX + 0x14)) {
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + -1;
  }
  if (*(int *)(in_EAX + 0x14) == 0) {
    *(undefined4 *)(in_EAX + 0xc) = 0;
  }
  return;
}

