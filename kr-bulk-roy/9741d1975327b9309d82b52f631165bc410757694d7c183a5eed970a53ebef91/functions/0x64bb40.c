
void FUN_0064bb40(void)

{
  float fVar1;
  int in_EAX;
  
  if (*(char *)(in_EAX + 0xd4) != '\0') {
    fVar1 = (*(float *)(*(int *)(in_EAX + 0x24) + 0x132c) -
            *(float *)(*(int *)(in_EAX + 0x24) + 0x1330)) + *(float *)(in_EAX + 0xb0);
    *(float *)(in_EAX + 0xb0) = fVar1;
    if (0.5 < fVar1) {
      *(undefined4 *)(in_EAX + 0xb0) = 0x3f000000;
      *(undefined1 *)(in_EAX + 0xd4) = 0;
    }
    FUN_0064bc10(*(float *)(in_EAX + 0xb0) * *(float *)(in_EAX + 0xc4) * 2.0,
                 *(float *)(in_EAX + 0xb0) * *(float *)(in_EAX + 200) * 2.0,
                 *(undefined1 *)(in_EAX + 0xd5));
    return;
  }
  *(undefined4 *)(in_EAX + 0xb0) = 0;
  return;
}

