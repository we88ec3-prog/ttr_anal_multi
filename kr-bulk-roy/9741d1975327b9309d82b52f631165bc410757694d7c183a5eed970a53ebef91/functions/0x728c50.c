
void FUN_00728c50(void)

{
  char *pcVar1;
  undefined4 *in_EAX;
  int *piVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = in_EAX[1];
  if (uVar5 < 2) {
    if (uVar5 != 0) {
      *(undefined1 *)in_EAX[0x11] = *(undefined1 *)*in_EAX;
    }
    piVar2 = __errno();
    *piVar2 = 0;
    sVar3 = _fread((void *)(in_EAX[0x11] + uVar5),1,0x4000 >> ((byte)uVar5 & 0x1f),
                   (FILE *)in_EAX[0x10]);
    if ((sVar3 == 0) && (iVar4 = _ferror((FILE *)in_EAX[0x10]), iVar4 != 0)) {
      in_EAX[0xe] = 0xffffffff;
    }
    in_EAX[1] = in_EAX[1] + sVar3;
    *in_EAX = in_EAX[0x11];
    if ((uint)in_EAX[1] < 2) {
      in_EAX[0x16] = in_EAX[1];
      return;
    }
  }
  pcVar1 = (char *)*in_EAX;
  if ((*pcVar1 != '\x1f') || (pcVar1[1] != -0x75)) {
    in_EAX[0x16] = 1;
    return;
  }
  in_EAX[1] = in_EAX[1] + -2;
  *in_EAX = pcVar1 + 2;
  iVar4 = FUN_00728be0();
  uVar5 = FUN_00728be0();
  if ((iVar4 != 8) || ((uVar5 & 0xe0) != 0)) {
    in_EAX[0xe] = 0xfffffffd;
    return;
  }
  iVar4 = 6;
  do {
    FUN_00728be0();
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if ((uVar5 & 4) != 0) {
    iVar4 = FUN_00728be0();
    iVar6 = FUN_00728be0();
    iVar4 = iVar4 + iVar6 * 0x100;
    do {
      if (iVar4 == 0) break;
      iVar6 = FUN_00728be0();
      iVar4 = iVar4 + -1;
    } while (iVar6 != -1);
  }
  if ((uVar5 & 8) != 0) {
    do {
      iVar4 = FUN_00728be0();
      if (iVar4 == 0) break;
    } while (iVar4 != -1);
  }
  if ((uVar5 & 0x10) != 0) {
    do {
      iVar4 = FUN_00728be0();
      if (iVar4 == 0) break;
    } while (iVar4 != -1);
  }
  if ((uVar5 & 2) != 0) {
    iVar4 = 2;
    do {
      FUN_00728be0();
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  in_EAX[0xe] = -(uint)(in_EAX[0xf] != 0) & 0xfffffffd;
  return;
}

