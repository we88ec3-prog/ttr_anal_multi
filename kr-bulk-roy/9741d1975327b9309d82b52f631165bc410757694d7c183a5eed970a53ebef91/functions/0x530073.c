
void FUN_00530073(void)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  short *psVar9;
  undefined4 *puVar10;
  uint uVar11;
  char *pcVar12;
  short *psVar13;
  int *unaff_EBX;
  uint unaff_EBP;
  int *piVar14;
  undefined1 in_ZF;
  
code_r0x00530073:
  if ((bool)in_ZF) {
    *(undefined4 *)(unaff_EBP - 4) = 0xffffffff;
    *(undefined ***)(unaff_EBP - 0xe4) = TiXmlDocument::vftable;
    if (0xf < *(uint *)(unaff_EBP - 0x84)) {
      FUN_0089120c(*(undefined4 *)(unaff_EBP - 0x98));
    }
    *(undefined4 *)(unaff_EBP - 0x84) = 0xf;
    *(int **)(unaff_EBP - 0x88) = unaff_EBX;
    *(undefined1 *)(unaff_EBP - 0x98) = 0;
    FUN_0072e040();
    ExceptionList = *(void **)(unaff_EBP - 0xc);
    __security_check_cookie(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
    return;
  }
  piVar14 = *(int **)(unaff_EBP - 0xf0);
  piVar3 = (int *)(**(code **)(*piVar14 + 0x14))();
  if (piVar3 != unaff_EBX) {
    piVar3 = (int *)FUN_007300a0(&DAT_00bfaf5c);
    if (piVar3 == unaff_EBX) {
LAB_0052fda5:
      uVar5 = 0;
    }
    else {
      piVar4 = piVar3 + 0xc;
      if (0xf < (uint)piVar3[0x11]) {
        piVar4 = (int *)*piVar4;
      }
      if (piVar4 == unaff_EBX) goto LAB_0052fda5;
      uVar5 = FUN_008917b4(piVar4);
    }
    iVar6 = *(int *)(unaff_EBP - 0xf8);
    *(undefined4 *)(unaff_EBP - 0xe8) = uVar5;
    FUN_008438c0(unaff_EBP - 0xe8);
    if ((*(int *)(unaff_EBP - 0xf4) != *(int *)(iVar6 + 4)) &&
       (piVar3 = *(int **)(*(int *)(unaff_EBP - 0xf4) + 0x10), *(int **)(unaff_EBP - 0xec) = piVar3,
       piVar3 != unaff_EBX)) {
      piVar3 = (int *)piVar14[6];
      *(int **)(unaff_EBP - 0xe8) = piVar3;
      if (piVar3 != unaff_EBX) {
        do {
          iVar6 = (**(code **)(*piVar3 + 0x14))();
          if (*(uint *)(iVar6 + 0x34) < 0x10) {
            pcVar12 = (char *)(iVar6 + 0x20);
          }
          else {
            pcVar12 = *(char **)(iVar6 + 0x20);
          }
          iVar7 = __stricmp(pcVar12,"EXPLAIN");
          if (iVar7 == 0) {
            if ((*(int **)(iVar6 + 0x18) != (int *)0x0) &&
               (iVar6 = (**(code **)(**(int **)(iVar6 + 0x18) + 0x30))(), iVar6 != 0)) {
              pcVar12 = (char *)(iVar6 + 0x20);
              if (0xf < *(uint *)(iVar6 + 0x34)) {
                pcVar12 = *(char **)pcVar12;
              }
              if (pcVar12 != (char *)0x0) {
                *(undefined4 *)(unaff_EBP - 0x38) = 7;
                *(undefined4 *)(unaff_EBP - 0x3c) = 0;
                *(undefined2 *)(unaff_EBP - 0x4c) = 0;
                *(undefined1 *)(unaff_EBP - 4) = 1;
                *(undefined4 *)(unaff_EBP - 0x54) = 0xf;
                *(undefined4 *)(unaff_EBP - 0x58) = 0;
                *(undefined1 *)(unaff_EBP - 0x68) = 0;
                pcVar8 = pcVar12;
                do {
                  cVar1 = *pcVar8;
                  pcVar8 = pcVar8 + 1;
                } while (cVar1 != '\0');
                FUN_00402a70(pcVar12,(int)pcVar8 - (int)(pcVar12 + 1));
                *(undefined1 *)(unaff_EBP - 4) = 2;
                FUN_00440130(unaff_EBP - 0x68);
                *(undefined1 *)(unaff_EBP - 4) = 1;
                if (0xf < *(uint *)(unaff_EBP - 0x54)) {
                  FUN_0089120c(*(undefined4 *)(unaff_EBP - 0x68));
                }
                if (*(uint *)(unaff_EBP - 0x38) < 8) {
                  psVar13 = (short *)(unaff_EBP - 0x4c);
LAB_0052fedc:
                  psVar9 = psVar13;
                  do {
                    sVar2 = *psVar9;
                    psVar9 = psVar9 + 1;
                  } while (sVar2 != 0);
                  FUN_00402160(psVar13,(int)psVar9 - (int)(psVar13 + 1) >> 1);
                  uVar5 = *(undefined4 *)(unaff_EBP - 0x4c);
                }
                else {
                  psVar13 = *(short **)(unaff_EBP - 0x4c);
                  uVar5 = 0;
                  if (psVar13 != (short *)0x0) goto LAB_0052fedc;
                }
                *(undefined1 *)(unaff_EBP - 4) = 0;
                if (7 < *(uint *)(unaff_EBP - 0x38)) {
                  FUN_0089120c(uVar5);
                }
              }
            }
          }
          else {
            iVar7 = __stricmp(pcVar12,"LEVEL");
            if (iVar7 != 0) {
              FUN_006edb60(&DAT_00c0f0c8);
              goto LAB_00530049;
            }
            iVar7 = FUN_007300a0(&DAT_00c0e044);
            if (iVar7 == 0) {
LAB_0052ff63:
              uVar11 = 0;
            }
            else {
              puVar10 = (undefined4 *)(iVar7 + 0x30);
              if (0xf < *(uint *)(iVar7 + 0x44)) {
                puVar10 = (undefined4 *)*puVar10;
              }
              if (puVar10 == (undefined4 *)0x0) goto LAB_0052ff63;
              uVar11 = FUN_008917b4(puVar10);
            }
            iVar7 = *(int *)(unaff_EBP - 0xec);
            if ((((*(char *)(iVar7 + 0x24) == '\x01') &&
                 (uVar11 <= (uint)((*(int *)(iVar7 + 0x54) - *(int *)(iVar7 + 0x50)) / 0x28))) &&
                (*(int *)(*(int *)(unaff_EBP - 0xec) + 0x50) + -0x28 + uVar11 * 0x28 != 0)) &&
               ((*(int **)(iVar6 + 0x18) != (int *)0x0 &&
                (iVar6 = (**(code **)(**(int **)(iVar6 + 0x18) + 0x30))(), iVar6 != 0)))) {
              pcVar12 = (char *)(iVar6 + 0x20);
              if (0xf < *(uint *)(iVar6 + 0x34)) {
                pcVar12 = *(char **)pcVar12;
              }
              if (pcVar12 != (char *)0x0) {
                *(undefined4 *)(unaff_EBP - 0x1c) = 0xf;
                *(undefined4 *)(unaff_EBP - 0x20) = 0;
                *(undefined1 *)(unaff_EBP - 0x30) = 0;
                pcVar8 = pcVar12;
                do {
                  cVar1 = *pcVar8;
                  pcVar8 = pcVar8 + 1;
                } while (cVar1 != '\0');
                FUN_00402a70(pcVar12,(int)pcVar8 - (int)(pcVar12 + 1));
                *(undefined1 *)(unaff_EBP - 4) = 3;
                FUN_00440130(unaff_EBP - 0x30);
                *(undefined1 *)(unaff_EBP - 4) = 0;
                if (0xf < *(uint *)(unaff_EBP - 0x1c)) {
                  FUN_0089120c(*(undefined4 *)(unaff_EBP - 0x30));
                }
                *(undefined4 *)(unaff_EBP - 0x1c) = 0xf;
                *(undefined4 *)(unaff_EBP - 0x20) = 0;
                *(undefined1 *)(unaff_EBP - 0x30) = 0;
              }
            }
          }
LAB_00530049:
          iVar6 = *(int *)(*(int *)(unaff_EBP - 0xe8) + 0x40);
          *(int *)(unaff_EBP - 0xe8) = iVar6;
          if (iVar6 == 0) goto code_r0x00530060;
          piVar3 = *(int **)(unaff_EBP - 0xe8);
        } while( true );
      }
    }
  }
  goto LAB_00530068;
code_r0x00530060:
  piVar14 = *(int **)(unaff_EBP - 0xf0);
  unaff_EBX = (int *)0x0;
LAB_00530068:
  piVar14 = (int *)piVar14[0x10];
  *(int **)(unaff_EBP - 0xf0) = piVar14;
  in_ZF = piVar14 == unaff_EBX;
  goto code_r0x00530073;
}

