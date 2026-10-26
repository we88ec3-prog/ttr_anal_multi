
ulonglong FUN_00867750(void)

{
  float fVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  byte bVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  uint in_EAX;
  byte *pbVar9;
  uint uVar10;
  int in_ECX;
  double *in_EDX;
  undefined3 uVar11;
  byte *pbVar12;
  bool bVar13;
  ushort uVar14;
  ulonglong uVar15;
  
  uVar10 = in_EAX;
  if (*(int *)(in_EAX + 4) == *(int *)(in_ECX + 4)) {
    pbVar9 = *(byte **)(in_EAX + 0xc);
    pbVar12 = *(byte **)(in_ECX + 0xc);
    do {
      bVar5 = *pbVar9;
      uVar11 = (undefined3)((uint)in_EDX >> 8);
      in_EDX = (double *)CONCAT31(uVar11,bVar5);
      bVar13 = bVar5 < *pbVar12;
      if (bVar5 != *pbVar12) {
LAB_00867787:
        uVar10 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
        goto LAB_0086778c;
      }
      if (bVar5 == 0) break;
      bVar5 = pbVar9[1];
      in_EDX = (double *)CONCAT31(uVar11,bVar5);
      bVar13 = bVar5 < pbVar12[1];
      if (bVar5 != pbVar12[1]) goto LAB_00867787;
      pbVar9 = pbVar9 + 2;
      pbVar12 = pbVar12 + 2;
    } while (bVar5 != 0);
    uVar10 = 0;
LAB_0086778c:
    if (uVar10 == 0) {
      in_EDX = (double *)(*(int *)(in_EAX + 4) + -1);
      uVar10 = 0;
      switch(in_EDX) {
      case (double *)0x0:
        return CONCAT44(CONCAT31((int3)((uint)in_EDX >> 8),**(char **)(in_EAX + 8)),
                        CONCAT31((int3)((uint)*(char **)(in_ECX + 8) >> 8),
                                 **(char **)(in_EAX + 8) == **(char **)(in_ECX + 8)));
      case (double *)0x1:
      case (double *)0xb:
      case (double *)0xc:
        return CONCAT44(**(int **)(in_EAX + 8),
                        CONCAT31((int3)((uint)*(int **)(in_ECX + 8) >> 8),
                                 **(int **)(in_EAX + 8) == **(int **)(in_ECX + 8)));
      case (double *)0x2:
        fVar1 = **(float **)(in_EAX + 8);
        fVar2 = **(float **)(in_ECX + 8);
        uVar10 = CONCAT22((short)((uint)*(float **)(in_EAX + 8) >> 0x10),
                          (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                          (ushort)(fVar2 == fVar1) << 0xe);
        if (fVar2 == fVar1) {
          return CONCAT44(in_EDX,CONCAT31((int3)(uVar10 >> 8),1));
        }
        break;
      case (double *)0x3:
        pbVar9 = *(byte **)(in_ECX + 8);
        pbVar12 = *(byte **)(in_EAX + 8);
        do {
          bVar5 = *pbVar12;
          bVar13 = bVar5 < *pbVar9;
          if (bVar5 != *pbVar9) {
LAB_0086781e:
            iVar8 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
            return CONCAT44(in_EDX,CONCAT31((int3)((uint)iVar8 >> 8),iVar8 == 0));
          }
          if (bVar5 == 0) break;
          bVar5 = pbVar12[1];
          bVar13 = bVar5 < pbVar9[1];
          if (bVar5 != pbVar9[1]) goto LAB_0086781e;
          pbVar12 = pbVar12 + 2;
          pbVar9 = pbVar9 + 2;
        } while (bVar5 != 0);
        return CONCAT44(in_EDX,1);
      case (double *)0x4:
        fVar1 = **(float **)(in_EAX + 8);
        fVar2 = **(float **)(in_ECX + 8);
        uVar10 = (uint)(ushort)((ushort)(fVar2 < fVar1) << 8 |
                                (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                               (ushort)(fVar2 == fVar1) << 0xe);
        if (fVar2 == fVar1) {
          fVar1 = (*(float **)(in_EAX + 8))[1];
          fVar2 = (*(float **)(in_ECX + 8))[1];
          uVar14 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                   (ushort)(fVar2 == fVar1) << 0xe;
          uVar10 = (uint)uVar14;
          if (fVar2 == fVar1) {
            return CONCAT44(in_EDX,CONCAT31((uint3)(byte)(uVar14 >> 8),1));
          }
        }
        break;
      case (double *)0x5:
        pfVar6 = *(float **)(in_EAX + 8);
        pfVar7 = *(float **)(in_ECX + 8);
        if (((*pfVar7 == *pfVar6) && (pfVar7[1] == pfVar6[1])) && (pfVar7[2] == pfVar6[2])) {
          return CONCAT44(pfVar6,1);
        }
        return ZEXT48(pfVar6) << 0x20;
      case (double *)0x6:
        uVar15 = FUN_00868b50();
        return uVar15;
      case (double *)0x7:
        pbVar9 = *(byte **)(in_ECX + 8);
        pbVar12 = *(byte **)(in_EAX + 8);
        uVar10 = 0x34;
        do {
          if (*(int *)pbVar9 != *(int *)pbVar12) {
            iVar8 = (uint)*pbVar9 - (uint)*pbVar12;
            if (((iVar8 == 0) && (iVar8 = (uint)pbVar9[1] - (uint)pbVar12[1], iVar8 == 0)) &&
               (iVar8 = (uint)pbVar9[2] - (uint)pbVar12[2], iVar8 == 0)) {
              iVar8 = (uint)pbVar9[3] - (uint)pbVar12[3];
            }
            return (ulonglong)CONCAT31((int3)(iVar8 >> 0x1f),(iVar8 >> 0x1f | 1U) == 0);
          }
          uVar10 = uVar10 - 4;
          pbVar12 = pbVar12 + 4;
          pbVar9 = pbVar9 + 4;
        } while (3 < uVar10);
        return 1;
      case (double *)0x8:
        pbVar9 = *(byte **)(in_ECX + 8);
        pbVar12 = *(byte **)(in_EAX + 8);
        uVar10 = 0x44;
        do {
          if (*(int *)pbVar9 != *(int *)pbVar12) {
            iVar8 = (uint)*pbVar9 - (uint)*pbVar12;
            if (((iVar8 == 0) && (iVar8 = (uint)pbVar9[1] - (uint)pbVar12[1], iVar8 == 0)) &&
               (iVar8 = (uint)pbVar9[2] - (uint)pbVar12[2], iVar8 == 0)) {
              iVar8 = (uint)pbVar9[3] - (uint)pbVar12[3];
            }
            return (ulonglong)CONCAT31((int3)(iVar8 >> 0x1f),(iVar8 >> 0x1f | 1U) == 0);
          }
          uVar10 = uVar10 - 4;
          pbVar12 = pbVar12 + 4;
          pbVar9 = pbVar9 + 4;
        } while (3 < uVar10);
        return 1;
      case (double *)0x9:
        in_EDX = *(double **)(in_EAX + 8);
        dVar3 = *in_EDX;
        dVar4 = **(double **)(in_ECX + 8);
        uVar10 = CONCAT22((short)((uint)*(double **)(in_ECX + 8) >> 0x10),
                          (ushort)(dVar4 < dVar3) << 8 | (ushort)(NAN(dVar4) || NAN(dVar3)) << 10 |
                          (ushort)(dVar4 == dVar3) << 0xe);
        if (dVar4 == dVar3) {
          return CONCAT44(in_EDX,CONCAT31((int3)(uVar10 >> 8),1));
        }
        break;
      case (double *)0xa:
        return CONCAT44(*(int **)(in_EAX + 8),
                        CONCAT31((int3)((uint)**(int **)(in_ECX + 8) >> 8),
                                 **(int **)(in_EAX + 8) == **(int **)(in_ECX + 8)));
      default:
        goto switchD_008677a3_default;
      }
    }
  }
  uVar10 = uVar10 & 0xffffff00;
switchD_008677a3_default:
  return CONCAT44(in_EDX,uVar10);
}

