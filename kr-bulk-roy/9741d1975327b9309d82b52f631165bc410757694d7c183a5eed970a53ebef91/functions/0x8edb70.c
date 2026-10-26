
void FUN_008edb70(void)

{
  int in_EAX;
  uint uVar1;
  uint *unaff_ESI;
  
  uVar1 = *unaff_ESI & 0xff;
  if (uVar1 == 0xff) {
    *(undefined1 *)(in_EAX + 0x151) = 1;
    return;
  }
  if (uVar1 != 0) {
    if (((*unaff_ESI & 0x100) != 0) && (*(ushort *)(in_EAX + 0xfc) <= uVar1)) {
      *(undefined1 *)(in_EAX + 0x151) = 1;
    }
    if (((*unaff_ESI & 0x200) != 0) && (*(char *)(in_EAX + 0x119) != '\0')) {
      *(undefined1 *)(in_EAX + 0x151) = 1;
    }
    if (((*unaff_ESI & 0x400) != 0) && (*(char *)(in_EAX + 0x11a) != '\0')) {
      *(undefined1 *)(in_EAX + 0x151) = 1;
    }
    if (((*unaff_ESI & 0x800) != 0) && (uVar1 < *(ushort *)(in_EAX + 0xfc))) {
      *(undefined1 *)(in_EAX + 0x151) = 0;
    }
    if (((*unaff_ESI & 0x1000) != 0) && (*(char *)(in_EAX + 0x119) != '\0')) {
      *(undefined1 *)(in_EAX + 0x151) = 0;
    }
    if ((*unaff_ESI & 0x2000) == 0) {
      return;
    }
    if (*(char *)(in_EAX + 0x11a) == '\0') {
      return;
    }
  }
  *(undefined1 *)(in_EAX + 0x151) = 0;
  return;
}

