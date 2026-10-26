
void FUN_008ee8e0(void)

{
  int unaff_ESI;
  
  if ((*(int *)(unaff_ESI + 0x10) < *(int *)(unaff_ESI + 0x130)) ||
     (*(ushort *)(unaff_ESI + 0x2c) <= *(ushort *)(unaff_ESI + 0x11c))) {
    if (*(char *)(unaff_ESI + 0x231) != '\0') {
      *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
    }
  }
  else if (0 < *(int *)(unaff_ESI + 0x130)) {
    do {
      *(int *)(unaff_ESI + 0x1c) = *(int *)(unaff_ESI + 0x1c) + -1;
      if (*(ushort *)(*(int *)(unaff_ESI + 0x18) + *(int *)(unaff_ESI + 0x1c) * 4) <
          *(ushort *)(unaff_ESI + 0x50)) {
        (**(code **)(unaff_ESI + 0x23c))();
        (**(code **)(unaff_ESI + 0x248))();
      }
      else if (*(char *)(unaff_ESI + 0x231) != '\0') {
        *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
        return;
      }
      *(int *)(unaff_ESI + 0x130) = *(int *)(unaff_ESI + 0x130) + -1;
    } while (0 < *(int *)(unaff_ESI + 0x130));
    *(undefined4 *)(unaff_ESI + 0x130) = 1;
    *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x1c);
    return;
  }
  *(undefined4 *)(unaff_ESI + 0x130) = 1;
  *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x1c);
  return;
}

