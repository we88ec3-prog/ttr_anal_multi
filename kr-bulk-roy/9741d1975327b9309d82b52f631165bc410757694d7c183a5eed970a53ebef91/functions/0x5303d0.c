
int FUN_005303d0(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  int in_ECX;
  int local_c;
  undefined1 local_8 [4];
  
  if ((*(int *)(in_EAX + 0x30) != 0) && (*(int *)(*(int *)(in_EAX + 0x30) + 4) != in_ECX)) {
    *(undefined4 *)(in_EAX + 0x30) = 0;
  }
  if (*(int *)(in_EAX + 0x30) == 0) {
    FUN_008438c0(local_8);
    if (local_c == *(int *)(in_EAX + 4)) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(local_c + 0x10);
    }
    *(undefined4 *)(in_EAX + 0x30) = uVar2;
  }
  iVar1 = *(int *)(in_EAX + 0x30);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 0x24) == '\x01')) {
    switch(*(undefined1 *)(iVar1 + 0x25)) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 8:
    case 9:
    case 10:
      return (int)*(short *)(iVar1 + 0x8a);
    }
  }
  return 0;
}

