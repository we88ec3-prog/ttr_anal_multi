
void FUN_00775ca0(undefined4 param_1)

{
  char cVar1;
  int *in_EAX;
  undefined4 uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *unaff_ESI;
  char *pcVar6;
  
  unaff_ESI[5] = *in_EAX - unaff_ESI[2];
  unaff_ESI[6] = in_EAX[1] - unaff_ESI[3];
  unaff_ESI[7] = in_EAX[2];
  uVar2 = FUN_008fed10();
  *unaff_ESI = uVar2;
  uVar2 = FUN_008fed10();
  unaff_ESI[1] = uVar2;
  unaff_ESI[2] = *in_EAX;
  unaff_ESI[3] = in_EAX[1];
  unaff_ESI[4] = in_EAX[2];
  *(undefined2 *)((int)unaff_ESI + 0x43) = *(undefined2 *)(unaff_ESI + 0x10);
  *(undefined1 *)((int)unaff_ESI + 0x45) = *(undefined1 *)((int)unaff_ESI + 0x42);
  *(short *)(unaff_ESI + 0x10) = (short)in_EAX[3];
  *(undefined1 *)((int)unaff_ESI + 0x42) = *(undefined1 *)((int)in_EAX + 0xe);
  pcVar6 = (char *)((int)in_EAX + 0xf);
  pcVar4 = (char *)(unaff_ESI + 0x10);
  puVar3 = unaff_ESI + 0x15;
  iVar5 = 3;
  do {
    cVar1 = pcVar4[3];
    if (cVar1 == '\0') {
LAB_00775d83:
      if (*pcVar4 == '\0') {
LAB_00775d93:
        puVar3[3] = 0;
        *puVar3 = 0;
      }
      else {
        puVar3[-3] = param_1;
        *puVar3 = 1;
      }
    }
    else {
      if (*pcVar4 == '\0') {
        if (cVar1 == '\0') goto LAB_00775d83;
        if (*pcVar4 == '\0') {
          *puVar3 = 6;
          puVar3[3] = (puVar3[6] != 3) - 1 & 5;
          goto LAB_00775da0;
        }
        if (cVar1 == '\0') goto LAB_00775d83;
        goto LAB_00775d93;
      }
      puVar3[3] = (-(uint)(puVar3[6] != 1) & 0xfffffffc) + 4;
      *puVar3 = 3;
    }
LAB_00775da0:
    uVar2 = 2;
    if (*pcVar6 == '\0') {
      uVar2 = puVar3[3];
    }
    puVar3[3] = uVar2;
    puVar3 = puVar3 + 1;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      unaff_ESI[8] = unaff_ESI[7];
      unaff_ESI[0x1b] = unaff_ESI[0x15];
      unaff_ESI[0x1c] = unaff_ESI[0x16];
      unaff_ESI[0x1d] = unaff_ESI[0x17];
      unaff_ESI[0x1e] = unaff_ESI[0x18];
      unaff_ESI[0x1f] = unaff_ESI[0x19];
      unaff_ESI[0x20] = unaff_ESI[0x1a];
      return;
    }
  } while( true );
}

