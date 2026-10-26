
float10 FUN_009032ae(void)

{
  int iVar1;
  ushort uVar2;
  float10 fVar3;
  double in_XMM0_Qa;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  
  uVar2 = ((ushort)((ulonglong)in_XMM0_Qa >> 0x30) & 0x7fff) + 0xc7e0;
  if (uVar2 < 0x8a9) {
    dVar11 = (in_XMM0_Qa * 10.185916357881302 + 1.080863910568919e+17) - 1.080863910568919e+17;
    dVar12 = (in_XMM0_Qa * 10.185916357881302 + 6755399441055744.0) - 6755399441055744.0;
    dVar4 = in_XMM0_Qa - dVar11 * 0.0981747704247482;
    dVar8 = in_XMM0_Qa - dVar12 * 0.09817477042452083;
    dVar5 = dVar4 - dVar11 * -6.716466596861444e-14;
    dVar9 = dVar8 - dVar12 * 1.6020900947399724e-13;
    iVar1 = ((int)ROUND(in_XMM0_Qa * 10.185916357881302) + 0x72900U & 0x1f) * 0xb0;
    dVar16 = (double)((ulonglong)(dVar11 * 6.716466596857464e-14 + dVar4) & 0xfffffffffffc0000);
    dVar17 = 1.0 / dVar16;
    dVar6 = dVar9 * dVar9;
    dVar10 = dVar9 * dVar9;
    dVar7 = dVar6 * dVar6;
    dVar14 = dVar9 * *(double *)(&DAT_00c5f4f0 + iVar1) + dVar9 * *(double *)(&DAT_00c5f4f8 + iVar1)
    ;
    dVar13 = (double)(*(ulonglong *)(&DAT_00c5f508 + iVar1) & (ulonglong)dVar17) -
             *(double *)(&DAT_00c5f4e0 + iVar1);
    dVar15 = dVar14 - dVar13;
    return (float10)(((dVar7 * dVar7 *
                       (*(double *)(&DAT_00c5f470 + iVar1) * dVar9 +
                        *(double *)(&DAT_00c5f460 + iVar1) +
                        (*(double *)(&DAT_00c5f490 + iVar1) * dVar9 +
                        *(double *)(&DAT_00c5f480 + iVar1)) * dVar6 +
                        *(double *)(&DAT_00c5f4a0 + iVar1) * dVar7 +
                       (*(double *)(&DAT_00c5f4c0 + iVar1) * dVar9 +
                        *(double *)(&DAT_00c5f4b0 + iVar1) +
                       *(double *)(&DAT_00c5f4d0 + iVar1) * dVar6) * dVar9 * dVar7) +
                       *(double *)(&UNK_00c5f478 + iVar1) * dVar9 +
                       *(double *)(&DAT_00c5f468 + iVar1) +
                       (*(double *)(&UNK_00c5f498 + iVar1) * dVar9 +
                       *(double *)(&DAT_00c5f488 + iVar1)) * dVar10 +
                       *(double *)(&UNK_00c5f4a8 + iVar1) * dVar10 * dVar10 +
                       (*(double *)(&UNK_00c5f4c8 + iVar1) * dVar9 +
                        *(double *)(&DAT_00c5f4b8 + iVar1) +
                       *(double *)(&UNK_00c5f4d8 + iVar1) * dVar10) * dVar9 * dVar10 * dVar10 +
                       (*(double *)(&DAT_00c5f4f0 + iVar1) + *(double *)(&DAT_00c5f4f8 + iVar1)) *
                       (((dVar8 - dVar9) - dVar12 * 1.6020900947399724e-13) -
                       dVar12 * 6.601874416867142e-25) + *(double *)(&DAT_00c5f4e8 + iVar1) +
                       dVar9 * *(double *)(&DAT_00c5f4f8 + iVar1) +
                       (dVar9 * *(double *)(&DAT_00c5f4f0 + iVar1) - dVar14) +
                      (dVar14 - (dVar13 + dVar15))) -
                     ((1.0 - dVar16 * (double)(*(ulonglong *)(&DAT_00c5f508 + iVar1) &
                                              (ulonglong)dVar17)) -
                     ((((dVar4 - dVar5) - dVar11 * -6.716466596861444e-14) -
                      dVar11 * 3.9801982271943437e-26) + (dVar5 - dVar16)) * dVar17) *
                     dVar17 * *(double *)(&DAT_00c5f500 + iVar1)) + dVar15);
  }
  if ((short)uVar2 < 0x8a9) {
    return (float10)((in_XMM0_Qa * 3.602879701896397e+16 + in_XMM0_Qa) * 2.7755575615628914e-17);
  }
  fVar3 = (float10)FUN_008ffd3f();
  return fVar3;
}

