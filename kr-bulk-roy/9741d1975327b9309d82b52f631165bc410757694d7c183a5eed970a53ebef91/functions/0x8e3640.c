
void FUN_008e3640(void)

{
  int in_EAX;
  
  if (*(char *)(in_EAX + 0x2d90) != '\0') {
    *(undefined1 *)(in_EAX + 0x2d91) = 1;
    FUN_008e3310(*(undefined4 *)(in_EAX + 0x2dd8),*(undefined4 *)(in_EAX + 0x2ddc));
    if (*(char *)(in_EAX + 0x2de0) != '\0') {
      FUN_008e17e0(in_EAX + 8,*(undefined4 *)(in_EAX + 0x2dc0),*(undefined4 *)(in_EAX + 0x2dc4),1);
    }
    *(undefined1 *)(in_EAX + 0x2d93) = 1;
    *(undefined2 *)(in_EAX + 0x2d90) = 0;
    *(undefined1 *)(in_EAX + 0x2de0) = 0;
  }
  return;
}

