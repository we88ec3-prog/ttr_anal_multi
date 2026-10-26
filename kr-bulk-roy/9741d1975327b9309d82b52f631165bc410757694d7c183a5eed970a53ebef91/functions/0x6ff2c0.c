
void FUN_006ff2c0(uint param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint in_EAX;
  int iVar5;
  byte *pbVar6;
  uint in_EDX;
  uint *unaff_ESI;
  int aiStack_c [2];
  
  unaff_ESI[0xe] = in_EAX;
  unaff_ESI[1] = 1;
  unaff_ESI[2] = 1;
  *(undefined1 *)(unaff_ESI + 0x11) = 0x2e;
  unaff_ESI[0xd] = param_1;
  unaff_ESI[8] = 0x11f;
  unaff_ESI[0xc] = 0;
  unaff_ESI[0x10] = in_EDX;
  iVar2 = ((undefined4 *)unaff_ESI[0xf])[2];
  iVar3 = *(int *)(param_1 + 0x10);
  iVar5 = (**(code **)(iVar3 + 0xc))
                    (*(undefined4 *)(iVar3 + 0x10),*(undefined4 *)unaff_ESI[0xf],iVar2,0x20);
  if (iVar5 == 0) {
    iVar5 = FUN_006fdb40(param_1,4);
  }
  *(int *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) + (0x20 - iVar2);
  *(int *)unaff_ESI[0xf] = iVar5;
  *(undefined4 *)(unaff_ESI[0xf] + 8) = 0x20;
  iVar2 = *(int *)unaff_ESI[0xe];
  *(int *)unaff_ESI[0xe] = iVar2 + -1;
  if (iVar2 != 0) {
    pbVar6 = *(byte **)(unaff_ESI[0xe] + 4);
    bVar1 = *pbVar6;
    *(byte **)(unaff_ESI[0xe] + 4) = pbVar6 + 1;
    *unaff_ESI = (uint)bVar1;
    return;
  }
  piVar4 = (int *)unaff_ESI[0xe];
  pbVar6 = (byte *)(*(code *)piVar4[2])(piVar4[4],piVar4[3],aiStack_c);
  if ((pbVar6 != (byte *)0x0) && (aiStack_c[0] != 0)) {
    piVar4[1] = (int)pbVar6;
    *piVar4 = aiStack_c[0] + -1;
    bVar1 = *pbVar6;
    piVar4[1] = (int)(pbVar6 + 1);
    *unaff_ESI = (uint)bVar1;
    return;
  }
  *unaff_ESI = 0xffffffff;
  return;
}

