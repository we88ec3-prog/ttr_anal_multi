
void FUN_008eec80(void)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int unaff_ESI;
  int *piVar5;
  undefined4 local_1c;
  int local_8;
  
  if (*(int *)(unaff_ESI + 0x10) < *(int *)(unaff_ESI + 0x130)) {
    cVar1 = *(char *)(unaff_ESI + 0x231);
  }
  else {
    if (((*(short *)(unaff_ESI + 0x158) == 0) || (*(short *)(unaff_ESI + 0x15a) == 0)) ||
       (*(short *)(unaff_ESI + 0x15c) == 0)) {
      bVar3 = true;
      bVar2 = true;
    }
    else {
      bVar2 = false;
      bVar3 = false;
    }
    if (*(ushort *)(unaff_ESI + 0x11e) < *(ushort *)(unaff_ESI + 0x2c)) {
      if (bVar2) {
        iVar4 = *(int *)(unaff_ESI + 0x30);
      }
      else {
        iVar4 = *(int *)(unaff_ESI + 0x38);
      }
      piVar5 = (int *)(iVar4 + (uint)*(ushort *)(unaff_ESI + 0x11e) * 8);
      if (*(ushort *)(unaff_ESI + 0x120) < *(ushort *)(unaff_ESI + 0x50)) {
        if (bVar2) {
LAB_008eed30:
          local_8 = (**(code **)(unaff_ESI + 0x240))();
        }
        else {
          if (*(int *)(unaff_ESI + 0xdc) == *(int *)(unaff_ESI + 0xe0)) goto LAB_008eed30;
          FUN_008b7f10(*(int *)(*(int *)(unaff_ESI + 0x5c) +
                               (uint)*(ushort *)(unaff_ESI + 0x120) * 8) - *piVar5,
                       *(int *)(unaff_ESI + 0xdc));
          FUN_008b7f10(*(int *)(*(int *)(unaff_ESI + 0x5c) + 4 +
                               (uint)*(ushort *)(unaff_ESI + 0x120) * 8) - piVar5[1],
                       *(undefined4 *)(unaff_ESI + 0xe0));
          local_8 = (**(code **)(unaff_ESI + 0x240))();
        }
        local_1c = (**(code **)(unaff_ESI + 0x23c))();
      }
      else {
        local_8 = 0;
        local_1c = 0;
      }
      iVar4 = *(int *)(unaff_ESI + 0x130);
      while (0 < iVar4) {
        *(int *)(unaff_ESI + 0x1c) = *(int *)(unaff_ESI + 0x1c) + -1;
        if (*(uint *)(*(int *)(unaff_ESI + 0x18) + *(int *)(unaff_ESI + 0x1c) * 4) <
            (uint)*(ushort *)(unaff_ESI + 0x74)) {
          if (bVar3) {
            iVar4 = (**(code **)(unaff_ESI + 0x240))();
          }
          else if (*(int *)(unaff_ESI + 0xdc) == *(int *)(unaff_ESI + 0xe0)) {
            iVar4 = (**(code **)(unaff_ESI + 0x240))();
          }
          else {
            iVar4 = (**(code **)(unaff_ESI + 0x240))();
          }
          (**(code **)(unaff_ESI + 0x23c))();
          if ((iVar4 != 0) && (local_8 != 0)) {
            FUN_008b7dc0(iVar4,local_1c,local_8);
          }
          (**(code **)(unaff_ESI + 0x248))();
        }
        else if (*(char *)(unaff_ESI + 0x231) != '\0') {
          *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
          return;
        }
        *(int *)(unaff_ESI + 0x130) = *(int *)(unaff_ESI + 0x130) + -1;
        iVar4 = *(int *)(unaff_ESI + 0x130);
      }
      goto LAB_008eeca3;
    }
    cVar1 = *(char *)(unaff_ESI + 0x231);
  }
  if (cVar1 != '\0') {
    *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
  }
LAB_008eeca3:
  *(undefined4 *)(unaff_ESI + 0x130) = 1;
  *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x1c);
  return;
}

