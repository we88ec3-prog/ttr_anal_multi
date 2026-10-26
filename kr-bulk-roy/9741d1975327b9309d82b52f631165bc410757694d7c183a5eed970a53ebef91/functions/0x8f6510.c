
void FUN_008f6510(void)

{
  int iVar1;
  int *piVar2;
  short *psVar3;
  int in_EAX;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int in_ECX;
  char *pcVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int *piVar15;
  short *psVar16;
  
  piVar9 = *(int **)(in_EAX + 0x34 + in_ECX * 0x1c);
  iVar11 = *(int *)(in_EAX + in_ECX * 0x1c + 0x44);
  iVar1 = *(int *)(*(int *)(in_EAX + 0x6c) + 0x28) * 8;
  piVar15 = piVar9 + *(int *)(in_EAX + 0x2c + in_ECX * 0x1c) * 0xc;
  if (in_ECX == 0) {
    uVar13 = *(undefined4 *)(in_EAX + 4);
  }
  else {
    uVar13 = *(undefined4 *)(in_EAX + 0xc);
  }
  iVar4 = FUN_008b7f40(0xc0,uVar13);
  if (piVar9 < piVar15) {
    pcVar7 = (char *)((int)piVar9 + 1);
    do {
      if ((*(int *)(pcVar7 + 0x27) != *(int *)(pcVar7 + 0x2b)) && (*pcVar7 == iVar11)) {
        piVar5 = piVar9 + 1;
        do {
          if (((piVar5 + -1 != (int *)(pcVar7 + -1)) &&
              ((int)*(char *)((int)piVar5 + -3) + (int)*pcVar7 == 0)) &&
             (iVar12 = (int)*(short *)((int)piVar5 + -2) - (int)*(short *)(pcVar7 + 1), -1 < iVar12)
             ) {
            iVar14 = (int)*(short *)(pcVar7 + 3);
            if ((int)*(short *)(pcVar7 + 3) < (int)(short)*piVar5) {
              iVar14 = (int)(short)*piVar5;
            }
            iVar10 = (int)*(short *)(pcVar7 + 5);
            if ((int)*(short *)((int)piVar5 + 2) < (int)*(short *)(pcVar7 + 5)) {
              iVar10 = (int)*(short *)((int)piVar5 + 2);
            }
            iVar10 = iVar10 - iVar14;
            if ((int)(iVar1 + (iVar1 >> 0x1f & 0x7ffU)) >> 0xb <= iVar10) {
              iVar14 = iVar12 * 8;
              if ((iVar14 < *(int *)(pcVar7 + 0x1f) * 9) &&
                 ((iVar14 < *(int *)(pcVar7 + 0x1f) * 7 || (*(int *)(pcVar7 + 0x23) < iVar10)))) {
                *(int *)(pcVar7 + 0x1f) = iVar12;
                *(int *)(pcVar7 + 0x23) = iVar10;
                *(int **)(pcVar7 + 0x13) = piVar5 + -1;
              }
              if ((iVar14 < piVar5[7] * 9) && ((iVar14 < piVar5[7] * 7 || (piVar5[8] < iVar10)))) {
                piVar5[8] = iVar10;
                piVar5[7] = iVar12;
                piVar5[4] = (int)(pcVar7 + -1);
              }
            }
          }
          piVar2 = piVar5 + 0xb;
          piVar5 = piVar5 + 0xc;
        } while (piVar2 < piVar15);
      }
      piVar5 = (int *)(pcVar7 + 0x2f);
      pcVar7 = pcVar7 + 0x30;
    } while (piVar5 < piVar15);
    if (piVar9 < piVar15) {
      piVar5 = piVar9 + 8;
      do {
        piVar2 = (int *)piVar5[-3];
        if ((((piVar2 != (int *)0x0) && ((int *)piVar2[5] == piVar5 + -8)) &&
            (*(short *)((int)piVar5 + -0x1e) < *(short *)((int)piVar2 + 2))) && (*piVar5 < iVar4)) {
          psVar16 = (short *)((int)piVar9 + 2);
          do {
            if (((*psVar16 <= *(short *)((int)piVar5 + -0x1e)) &&
                (piVar5 + -8 != (int *)(psVar16 + -1))) &&
               ((psVar3 = *(short **)(psVar16 + 9), psVar3 != (short *)0x0 &&
                (*(int **)(psVar3 + 10) == (int *)(psVar16 + -1))))) {
              if ((*(short *)((int)piVar2 + 2) <= psVar3[1]) &&
                 ((*(short *)((int)piVar5 + -0x1e) != *psVar16 ||
                  (*(short *)((int)piVar2 + 2) != psVar3[1])))) {
                iVar11 = *(int *)(psVar16 + 0xf);
                if ((*piVar5 < iVar11) &&
                   (iVar1 = *piVar5 * 4, iVar1 - iVar11 != 0 && iVar11 <= iVar1)) {
                  if (piVar5[1] < *(int *)(psVar16 + 0x11) * 3) {
                    piVar2[5] = 0;
                    piVar5[-3] = 0;
                    break;
                  }
                  piVar8 = piVar9 + 5;
                  iVar11 = (uint)((int)piVar15 + (-1 - (int)piVar9)) / 0x30 + 1;
                  do {
                    piVar6 = piVar2;
                    if ((short *)*piVar8 == psVar16 + -1) {
LAB_008f6756:
                      piVar8[1] = (int)piVar6;
                      *piVar8 = 0;
                    }
                    else if ((short *)*piVar8 == psVar3) {
                      piVar6 = piVar5 + -8;
                      goto LAB_008f6756;
                    }
                    piVar8 = piVar8 + 0xc;
                    iVar11 = iVar11 + -1;
                  } while (iVar11 != 0);
                }
              }
            }
            piVar8 = (int *)(psVar16 + 0x17);
            psVar16 = psVar16 + 0x18;
          } while (piVar8 < piVar15);
        }
        piVar2 = piVar5 + 4;
        piVar5 = piVar5 + 0xc;
      } while (piVar2 < piVar15);
      if (piVar9 < piVar15) {
        piVar9 = piVar9 + 5;
        do {
          iVar11 = *piVar9;
          if ((iVar11 != 0) &&
             (*(int *)(iVar11 + 0x1c) = *(int *)(iVar11 + 0x1c) + 1,
             *(int **)(iVar11 + 0x14) != piVar9 + -5)) {
            *piVar9 = 0;
            if ((*(int *)(iVar11 + 0x20) < iVar4) || (piVar9[3] < *(int *)(iVar11 + 0x20) * 4)) {
              piVar9[1] = *(int *)(iVar11 + 0x14);
            }
            else {
              *(int *)(iVar11 + 0x1c) = *(int *)(iVar11 + 0x1c) + -1;
            }
          }
          piVar5 = piVar9 + 7;
          piVar9 = piVar9 + 0xc;
        } while (piVar5 < piVar15);
      }
    }
  }
  return;
}

