
void FUN_0056cf10(int *param_1)

{
  short *psVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  byte bVar5;
  char cVar6;
  short sVar7;
  ushort uVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  short *psVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  int *piVar17;
  float *pfVar18;
  float10 fVar19;
  int *piStack_f4;
  int iStack_40;
  int iStack_30;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0094776e;
  local_14 = ExceptionList;
  uVar11 = DAT_00d61f20 ^ (uint)&stack0xfffffef0;
  ExceptionList = &local_14;
  FUN_0056ee50(*param_1);
  piVar12 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))(uVar11);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  piStack_f4 = (int *)*DAT_00fab13c;
  if (piStack_f4 != DAT_00fab13c) {
    do {
      piVar9 = (int *)piStack_f4[4];
      cVar6 = (char)piVar9[1];
      if ((cVar6 == '\0') || (cVar6 == '\x01')) {
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          uStack_c = 1;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          uStack_c = 0xffffffff;
        }
        iVar13 = FUN_004f7a70();
        if (*(char *)(iVar13 + 0x60) != '\0') {
          if (piVar9 != piVar12) {
            if ((DAT_00f94390 & 1) == 0) {
              DAT_00f94390 = DAT_00f94390 | 1;
              uStack_c = 5;
              FUN_004e1590();
              _atexit((_func_4879 *)&LAB_00bccc80);
              uStack_c = 0xffffffff;
            }
            if (DAT_00f9392c == 7) {
LAB_0056db36:
              if ((DAT_00fb1378 & 1) == 0) {
                DAT_00fb1378 = DAT_00fb1378 | 1;
                uStack_c = 7;
                FUN_00539c20();
                _atexit((_func_4879 *)&LAB_00bccfb0);
                uStack_c = 0xffffffff;
              }
              if (DAT_00fb7258 == 0) {
                puVar16 = (undefined4 *)FUN_00891268(0x48);
                uStack_c = 10;
                if (puVar16 == (undefined4 *)0x0) {
LAB_0056dd44:
                  puVar16 = (undefined4 *)0x0;
                  goto LAB_0056dd47;
                }
                uVar8 = *(ushort *)(piVar9 + 1);
                *puVar16 = 4;
                puVar16[1] = (uint)uVar8;
                puVar16[2] = 1;
                *(undefined1 *)(puVar16 + 3) = 1;
                puVar16[4] = piVar9[0x28];
              }
              else {
                iVar13 = FUN_00539aa0(piVar9[0x27]);
                if (iVar13 == 0) {
                  puVar16 = (undefined4 *)FUN_00891268(0x48);
                  uStack_c = 9;
                  if (puVar16 == (undefined4 *)0x0) {
                    iVar13 = *param_1;
                    puVar16 = (undefined4 *)0x0;
                  }
                  else {
                    puVar16[1] = (uint)*(ushort *)(piVar9 + 1);
                    *puVar16 = 4;
                    puVar16[2] = 1;
                    *(undefined1 *)(puVar16 + 3) = 1;
                    puVar16[4] = piVar9[0x28];
                    puVar16[5] = piVar9[0x29];
                    puVar16[7] = 0;
                    puVar16[6] = 0;
                    puVar16[8] = 0;
                    puVar16[0xe] = 7;
                    puVar16[0xd] = 0;
                    *(undefined2 *)(puVar16 + 9) = 0;
                    FUN_00402160(&DAT_00bed1fc,0);
                    puVar16[0x10] = 0;
                    puVar16[0x11] = 0;
                    iVar13 = *param_1;
                  }
                  goto LAB_0056dd58;
                }
                puVar16 = (undefined4 *)FUN_00891268(0x48);
                uStack_c = 8;
                if (puVar16 == (undefined4 *)0x0) goto LAB_0056dd44;
                uVar8 = *(ushort *)(piVar9 + 1);
                *puVar16 = 2;
                puVar16[1] = (uint)uVar8;
                puVar16[2] = 1;
                *(undefined1 *)(puVar16 + 3) = 1;
                puVar16[4] = piVar9[0x28];
              }
              iVar13 = piVar9[0x29];
              puVar16[7] = 0;
              puVar16[6] = 0;
              puVar16[5] = iVar13;
              puVar16[8] = 0;
              puVar16[0xe] = 7;
              puVar16[0xd] = 0;
              *(undefined2 *)(puVar16 + 9) = 0;
              FUN_00402160(&DAT_00bed1fc,0);
              puVar16[0x10] = 0;
              puVar16[0x11] = 0;
              goto LAB_0056dd47;
            }
            if ((DAT_00f94390 & 1) == 0) {
              DAT_00f94390 = DAT_00f94390 | 1;
              uStack_c = 6;
              FUN_004e1590();
              _atexit((_func_4879 *)&LAB_00bccc80);
              uStack_c = 0xffffffff;
            }
            if (((DAT_00f9392c == 0x17) ||
                (iVar13 = FUN_00404ba0(), *(int *)(iVar13 + 0x5f4c) == 0x18)) ||
               (iVar13 = FUN_00404ba0(), *(int *)(iVar13 + 0x5f4c) == 3)) goto LAB_0056db36;
            if (cVar6 == '\0') {
              uVar11 = piVar9[0x10a];
            }
            else {
              iVar13 = (**(code **)(*piVar9 + 0x70))();
              uVar11 = (uint)(iVar13 < 0x1e);
            }
            iVar13 = FUN_004c9580(piVar9);
            if (iVar13 == 0x10) {
              iVar13 = FUN_00891268(0x48);
              if (uVar11 == 0) {
                uStack_c = 0xc;
                if (iVar13 == 0) goto LAB_0056d9e8;
                puVar16 = (undefined4 *)FUN_0056fbf0(2,(short)piVar9[1],1,0);
                iVar13 = *param_1;
              }
              else {
                uStack_c = 0xb;
                if (iVar13 == 0) {
LAB_0056d9e8:
                  puVar16 = (undefined4 *)0x0;
                  iVar13 = *param_1;
                }
                else {
                  puVar16 = (undefined4 *)FUN_0056fbf0(4,(short)piVar9[1],1,0);
                  iVar13 = *param_1;
                }
              }
            }
            else if (iVar13 == 0x11) {
              iVar13 = FUN_00891268(0x48);
              if (uVar11 == 0) {
                uStack_c = 0xe;
                if (iVar13 == 0) goto LAB_0056d9e8;
                puVar16 = (undefined4 *)FUN_0056fbf0(3,(short)piVar9[1],piVar9[0x24] + 1,0);
                iVar13 = *param_1;
              }
              else {
                uStack_c = 0xd;
                if (iVar13 == 0) goto LAB_0056d9e8;
                puVar16 = (undefined4 *)FUN_0056fbf0(4,(short)piVar9[1],piVar9[0x24] + 1,0);
                iVar13 = *param_1;
              }
            }
            else {
              if (iVar13 != 0x12) goto switchD_0056d0a8_default;
              iVar13 = FUN_00891268(0x48);
              uStack_c = 0xf;
              if (iVar13 == 0) {
                puVar16 = (undefined4 *)0x0;
                iVar13 = *param_1;
              }
              else {
                puVar16 = (undefined4 *)FUN_0056fbf0(5,(short)piVar9[1],piVar9[0x24] + 1,0);
                iVar13 = *param_1;
              }
            }
            goto LAB_0056dd58;
          }
          puVar16 = (undefined4 *)FUN_00891268(0x48);
          uStack_c = 2;
          if (puVar16 == (undefined4 *)0x0) {
            puVar16 = (undefined4 *)0x0;
          }
          else {
            bVar5 = *(byte *)(piVar9 + 0xe9);
            fVar2 = *(float *)(*param_1 + 0x68);
            if ((DAT_00fb7c18 & 1) == 0) {
              DAT_00fb7c18 = DAT_00fb7c18 | 1;
              FUN_004449d0();
            }
            fVar3 = (float)(&DAT_00fb7c20)[bVar5];
            puVar16[1] = (uint)*(ushort *)(piVar9 + 1);
            *puVar16 = 1;
            puVar16[2] = 1;
            *(undefined1 *)(puVar16 + 3) = 1;
            puVar16[4] = piVar9[0x28];
            puVar16[5] = piVar9[0x29];
            puVar16[6] = (fVar2 - fVar3) + 3.1415927;
            puVar16[8] = 0;
            puVar16[7] = 0;
            puVar16[0xe] = 7;
            puVar16[0xd] = 0;
            *(undefined2 *)(puVar16 + 9) = 0;
            FUN_00402160(&DAT_00bed1fc,0);
            puVar16[0x10] = 0;
            puVar16[0x11] = 0;
          }
          uStack_c = 0xffffffff;
          FUN_0056f5c0(*param_1,puVar16);
          piVar17 = (int *)FUN_0056f830();
          iVar10 = *piVar17;
          iVar13 = piVar17[1];
          if (iStack_30 != 0) {
            FUN_0089120c(iStack_30);
          }
          iStack_30 = 0;
          if (iVar10 != iVar13) {
            uVar11 = 0;
            while( true ) {
              piVar17 = (int *)FUN_0056f830();
              iVar13 = piVar17[1];
              iVar10 = *piVar17;
              if (iStack_40 != 0) {
                FUN_0089120c(iStack_40);
              }
              iStack_40 = 0;
              if ((uint)(iVar13 - iVar10 >> 3) <= uVar11) break;
              pfVar18 = (float *)FUN_0056f850(*param_1,piVar9[0x28],piVar9[0x29]);
              fVar2 = *pfVar18;
              fVar3 = pfVar18[1];
              iVar13 = *param_1;
              fVar19 = (float10)FUN_008fedca();
              if ((fVar2 != *(float *)(*(int *)(iVar13 + 0x74) + uVar11 * 8)) ||
                 (fVar3 != *(float *)(*(int *)(iVar13 + 0x74) + 4 + uVar11 * 8))) {
                puVar16 = (undefined4 *)FUN_00891268(0x48);
                uStack_c = 3;
                if (puVar16 == (undefined4 *)0x0) {
                  puVar16 = (undefined4 *)0x0;
                }
                else {
                  fVar4 = *(float *)(*param_1 + 0x68);
                  puVar16[4] = fVar2;
                  puVar16[5] = fVar3;
                  puVar16[6] = fVar4 - ((float)fVar19 + 1.5707964);
                  puVar16[8] = 0;
                  *puVar16 = 0xc;
                  puVar16[1] = uVar11;
                  puVar16[2] = 4;
                  *(undefined1 *)(puVar16 + 3) = 1;
                  puVar16[7] = 0;
                  puVar16[0xe] = 7;
                  puVar16[0xd] = 0;
                  *(undefined2 *)(puVar16 + 9) = 0;
                  FUN_00402160(&DAT_00bed1fc,0);
                  puVar16[0x10] = 0;
                  puVar16[0x11] = 0;
                }
                uStack_c = 0xffffffff;
                FUN_0056f5c0(*param_1,puVar16);
                puVar16 = (undefined4 *)FUN_00891268(0x48);
                uStack_c = 4;
                if (puVar16 == (undefined4 *)0x0) {
                  puVar16 = (undefined4 *)0x0;
                }
                else {
                  puVar16[2] = uVar11 + 1;
                  puVar16[7] = 0;
                  puVar16[4] = fVar2;
                  puVar16[5] = fVar3;
                  *puVar16 = 0xd;
                  puVar16[1] = uVar11;
                  *(undefined1 *)(puVar16 + 3) = 1;
                  puVar16[6] = 0;
                  puVar16[8] = 0;
                  puVar16[0xe] = 7;
                  puVar16[0xd] = 0;
                  *(undefined2 *)(puVar16 + 9) = 0;
                  FUN_00402160(&DAT_00bed1fc,0);
                  puVar16[0x10] = 0;
                  puVar16[0x11] = 0;
                }
                uStack_c = 0xffffffff;
                FUN_0056f5c0(*param_1,puVar16);
              }
              uVar11 = uVar11 + 1;
            }
          }
        }
      }
      else if (cVar6 == '\x06') {
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          uStack_c = 0x10;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          uStack_c = 0xffffffff;
        }
        iVar13 = FUN_004f7a70();
        if (*(uint *)(iVar13 + 0x30) < 8) {
          psVar14 = (short *)(iVar13 + 0x1c);
        }
        else {
          psVar14 = *(short **)(iVar13 + 0x1c);
        }
        psVar1 = psVar14 + 1;
        do {
          sVar7 = *psVar14;
          psVar14 = psVar14 + 1;
        } while (sVar7 != 0);
        if ((int)psVar14 - (int)psVar1 >> 1 != 0) {
          iVar13 = piVar9[0x22];
          if ((DAT_00fab29c & 1) == 0) {
            DAT_00fab29c = DAT_00fab29c | 1;
            uStack_c = 0x11;
            FUN_004ffe60();
            _atexit((_func_4879 *)&LAB_00bccf00);
            uStack_c = 0xffffffff;
          }
          uVar15 = FUN_00500a80(&DAT_00fab2a0,(short)iVar13);
          switch(uVar15) {
          case 0:
            iVar13 = FUN_00891268(0x48);
            uStack_c = 0x12;
            if (iVar13 == 0) {
LAB_0056d11b:
              puVar16 = (undefined4 *)0x0;
            }
            else {
              puVar16 = (undefined4 *)FUN_0056fbf0(6,(short)piVar9[1],1,0);
            }
            break;
          case 1:
            iVar13 = FUN_00891268(0x48);
            uStack_c = 0x13;
            if (iVar13 == 0) goto LAB_0056d11b;
            puVar16 = (undefined4 *)FUN_0056fbf0(6,(short)piVar9[1],2,0);
            break;
          case 2:
            iVar13 = FUN_00891268(0x48);
            uStack_c = 0x16;
            if (iVar13 == 0) goto LAB_0056d11b;
            puVar16 = (undefined4 *)FUN_0056fbf0(6,(short)piVar9[1],5,0);
            break;
          case 3:
            iVar13 = FUN_00891268(0x48);
            uStack_c = 0x14;
            if (iVar13 == 0) goto LAB_0056d11b;
            puVar16 = (undefined4 *)FUN_0056fbf0(6,(short)piVar9[1],3,0);
            break;
          case 4:
            iVar13 = FUN_00891268(0x48);
            uStack_c = 0x17;
            if (iVar13 == 0) goto LAB_0056d11b;
            puVar16 = (undefined4 *)FUN_0056fbf0(6,(short)piVar9[1],6,0);
            break;
          case 5:
            iVar13 = FUN_00891268(0x48);
            uStack_c = 0x15;
            if (iVar13 == 0) goto LAB_0056d11b;
            puVar16 = (undefined4 *)FUN_0056fbf0(6,(short)piVar9[1],4,0);
            break;
          case 6:
            iVar13 = FUN_00891268(0x48);
            uStack_c = 0x18;
            if (iVar13 == 0) goto LAB_0056d11b;
            puVar16 = (undefined4 *)FUN_0056fbf0(6,(short)piVar9[1],2,0);
            break;
          default:
            goto switchD_0056d0a8_default;
          }
LAB_0056dd47:
          iVar13 = *param_1;
LAB_0056dd58:
          uStack_c = 0xffffffff;
          FUN_0056f5c0(iVar13,puVar16);
        }
      }
switchD_0056d0a8_default:
      if (*(char *)((int)piStack_f4 + 0x15) == '\0') {
        piVar9 = (int *)piStack_f4[2];
        if (*(char *)((int)piVar9 + 0x15) == '\0') {
          cVar6 = *(char *)(*piVar9 + 0x15);
          piStack_f4 = piVar9;
          piVar9 = (int *)*piVar9;
          while (cVar6 == '\0') {
            cVar6 = *(char *)(*piVar9 + 0x15);
            piStack_f4 = piVar9;
            piVar9 = (int *)*piVar9;
          }
        }
        else {
          cVar6 = *(char *)(piStack_f4[1] + 0x15);
          piVar17 = (int *)piStack_f4[1];
          piVar9 = piStack_f4;
          while ((piStack_f4 = piVar17, cVar6 == '\0' && (piVar9 == (int *)piStack_f4[2]))) {
            cVar6 = *(char *)(piStack_f4[1] + 0x15);
            piVar17 = (int *)piStack_f4[1];
            piVar9 = piStack_f4;
          }
        }
      }
    } while (piStack_f4 != DAT_00fab13c);
  }
  ExceptionList = local_14;
  return;
}

