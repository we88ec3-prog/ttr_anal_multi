
/* WARNING: Removing unreachable block (ram,0x0085c3b1) */
/* WARNING: Removing unreachable block (ram,0x0085c368) */
/* WARNING: Removing unreachable block (ram,0x0085c3a2) */
/* WARNING: Removing unreachable block (ram,0x0085c3ab) */
/* WARNING: Removing unreachable block (ram,0x0085c3ba) */
/* WARNING: Removing unreachable block (ram,0x0085c3d6) */
/* WARNING: Removing unreachable block (ram,0x0085c3e5) */
/* WARNING: Removing unreachable block (ram,0x0085c42b) */

void FUN_0085bc60(void)

{
  byte bVar1;
  int iVar2;
  byte ****ppppbVar3;
  int in_ECX;
  byte *pbVar4;
  char *pcVar5;
  int *piVar6;
  bool bVar7;
  byte *local_108;
  int local_100;
  uint local_d4;
  int local_c4;
  int local_b4;
  int local_ac;
  uint local_90;
  uint local_88 [4];
  undefined4 local_78;
  uint local_74;
  uint local_6c [4];
  undefined4 local_5c;
  uint local_58;
  byte ***local_50 [3];
  int local_44;
  int local_40;
  uint local_3c;
  byte ***local_34 [4];
  int local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8._0_1_ = 0xff;
  local_8._1_3_ = 0xffffff;
  puStack_c = &LAB_009281d1;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0085d0d0();
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  local_90 = 0;
  if (local_d4 != 0) {
    do {
      iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
      if (((iVar2 != 0) &&
          ((**(code **)(**(int **)(in_ECX + 4) + 0x10))(), local_108 != (byte *)0x0)) &&
         (local_100 == 3)) {
        pcVar5 = "STANDARDSGLOBAL";
        pbVar4 = local_108;
        do {
          bVar1 = *pbVar4;
          bVar7 = bVar1 < (byte)*pcVar5;
          if (bVar1 != *pcVar5) {
LAB_0085bd40:
            iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
            goto LAB_0085bd45;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar7 = bVar1 < (byte)pcVar5[1];
          if (bVar1 != pcVar5[1]) goto LAB_0085bd40;
          pbVar4 = pbVar4 + 2;
          pcVar5 = pcVar5 + 2;
        } while (bVar1 != 0);
        iVar2 = 0;
LAB_0085bd45:
        if (iVar2 == 0) {
          pbVar4 = local_108;
          do {
            bVar1 = *pbVar4;
            pbVar4 = pbVar4 + 1;
          } while (bVar1 != 0);
          if ((int)pbVar4 - (int)(local_108 + 1) == 0xf) {
            local_5c = 0;
            local_6c[0] = local_6c[0] & 0xffffff00;
            local_8 = 0;
            local_58 = (int)pbVar4 - (int)(local_108 + 1);
            FUN_008714b0();
            FUN_00403040(local_6c,0,0xffffffff);
            FUN_0085c4b0(in_ECX);
            iVar2 = *(int *)(in_ECX + 0x54) - *(int *)(in_ECX + 0x50) >> 2;
            if (iVar2 != 0) {
              piVar6 = *(int **)(in_ECX + 0x50);
              do {
                if (*(int *)(*piVar6 + 8) == 9) {
                  *(int *)(in_ECX + 0x88) = *piVar6;
                }
                piVar6 = piVar6 + 1;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
            }
            *(undefined4 *)(in_ECX + 8) = 1;
            local_3c = 0xf;
            local_40 = 0;
            local_50[0] = (byte ***)((uint)local_50[0] & 0xffffff00);
            local_8._0_1_ = 1;
            FUN_008714b0();
            if (local_40 != 0) {
              ppppbVar3 = (byte ****)local_50[0];
              if (local_3c < 0x10) {
                ppppbVar3 = local_50;
              }
              pcVar5 = "scene";
              do {
                bVar1 = *(byte *)ppppbVar3;
                bVar7 = bVar1 < (byte)*pcVar5;
                if (bVar1 != *pcVar5) {
LAB_0085be70:
                  iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
                  goto LAB_0085be75;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppppbVar3 + 1);
                bVar7 = bVar1 < (byte)pcVar5[1];
                if (bVar1 != pcVar5[1]) goto LAB_0085be70;
                ppppbVar3 = (byte ****)((int)ppppbVar3 + 2);
                pcVar5 = pcVar5 + 2;
              } while (bVar1 != 0);
              iVar2 = 0;
LAB_0085be75:
              if (iVar2 == 0) {
                ppppbVar3 = (byte ****)local_50[0];
                if (local_3c < 0x10) {
                  ppppbVar3 = local_50;
                }
                pbVar4 = (byte *)((int)ppppbVar3 + 1);
                do {
                  bVar1 = *(byte *)ppppbVar3;
                  ppppbVar3 = (byte ****)((int)ppppbVar3 + 1);
                } while (bVar1 != 0);
                if ((int)ppppbVar3 - (int)pbVar4 == 5) {
                  *(undefined4 *)(in_ECX + 8) = 0;
                  goto LAB_0085bf03;
                }
              }
              ppppbVar3 = (byte ****)local_50[0];
              if (local_3c < 0x10) {
                ppppbVar3 = local_50;
              }
              pcVar5 = "share";
              do {
                bVar1 = *(byte *)ppppbVar3;
                bVar7 = bVar1 < (byte)*pcVar5;
                if (bVar1 != *pcVar5) {
LAB_0085bed2:
                  iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
                  goto LAB_0085bed7;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppppbVar3 + 1);
                bVar7 = bVar1 < (byte)pcVar5[1];
                if (bVar1 != pcVar5[1]) goto LAB_0085bed2;
                ppppbVar3 = (byte ****)((int)ppppbVar3 + 2);
                pcVar5 = pcVar5 + 2;
              } while (bVar1 != 0);
              iVar2 = 0;
LAB_0085bed7:
              if (iVar2 == 0) {
                ppppbVar3 = (byte ****)local_50[0];
                if (local_3c < 0x10) {
                  ppppbVar3 = local_50;
                }
                pbVar4 = (byte *)((int)ppppbVar3 + 1);
                do {
                  bVar1 = *(byte *)ppppbVar3;
                  ppppbVar3 = (byte ****)((int)ppppbVar3 + 1);
                } while (bVar1 != 0);
                if ((int)ppppbVar3 - (int)pbVar4 == 5) {
                  *(undefined4 *)(in_ECX + 8) = 2;
                }
              }
            }
LAB_0085bf03:
            local_20 = 0xf;
            local_24 = 0;
            local_34[0] = (byte ***)((uint)local_34[0] & 0xffffff00);
            local_8 = CONCAT31(local_8._1_3_,2);
            FUN_008714b0();
            if (local_24 != 0) {
              ppppbVar3 = (byte ****)local_34[0];
              if (local_20 < 0x10) {
                ppppbVar3 = local_34;
              }
              pcVar5 = "zbacktofront";
              do {
                bVar1 = *(byte *)ppppbVar3;
                bVar7 = bVar1 < (byte)*pcVar5;
                if (bVar1 != *pcVar5) {
LAB_0085bf70:
                  iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
                  goto LAB_0085bf75;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppppbVar3 + 1);
                bVar7 = bVar1 < (byte)pcVar5[1];
                if (bVar1 != pcVar5[1]) goto LAB_0085bf70;
                ppppbVar3 = (byte ****)((int)ppppbVar3 + 2);
                pcVar5 = pcVar5 + 2;
              } while (bVar1 != 0);
              iVar2 = 0;
LAB_0085bf75:
              if (iVar2 == 0) {
                ppppbVar3 = (byte ****)local_34[0];
                if (local_20 < 0x10) {
                  ppppbVar3 = local_34;
                }
                pbVar4 = (byte *)((int)ppppbVar3 + 1);
                do {
                  bVar1 = *(byte *)ppppbVar3;
                  ppppbVar3 = (byte ****)((int)ppppbVar3 + 1);
                } while (bVar1 != 0);
                if ((int)ppppbVar3 - (int)pbVar4 == 0xc) {
                  *(undefined4 *)(in_ECX + 0xc) = 2;
                  goto LAB_0085c0c5;
                }
              }
              ppppbVar3 = (byte ****)local_34[0];
              if (local_20 < 0x10) {
                ppppbVar3 = local_34;
              }
              pcVar5 = "zfronttoback";
              do {
                bVar1 = *(byte *)ppppbVar3;
                bVar7 = bVar1 < (byte)*pcVar5;
                if (bVar1 != *pcVar5) {
LAB_0085bfd1:
                  iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
                  goto LAB_0085bfd6;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppppbVar3 + 1);
                bVar7 = bVar1 < (byte)pcVar5[1];
                if (bVar1 != pcVar5[1]) goto LAB_0085bfd1;
                ppppbVar3 = (byte ****)((int)ppppbVar3 + 2);
                pcVar5 = pcVar5 + 2;
              } while (bVar1 != 0);
              iVar2 = 0;
LAB_0085bfd6:
              if (iVar2 == 0) {
                ppppbVar3 = (byte ****)local_34[0];
                if (local_20 < 0x10) {
                  ppppbVar3 = local_34;
                }
                pbVar4 = (byte *)((int)ppppbVar3 + 1);
                do {
                  bVar1 = *(byte *)ppppbVar3;
                  ppppbVar3 = (byte ****)((int)ppppbVar3 + 1);
                } while (bVar1 != 0);
                if ((int)ppppbVar3 - (int)pbVar4 == 0xc) {
                  *(undefined4 *)(in_ECX + 0xc) = 1;
                  goto LAB_0085c0c5;
                }
              }
              ppppbVar3 = (byte ****)local_34[0];
              if (local_20 < 0x10) {
                ppppbVar3 = local_34;
              }
              pcVar5 = "arbitrary";
              do {
                bVar1 = *(byte *)ppppbVar3;
                bVar7 = bVar1 < (byte)*pcVar5;
                if (bVar1 != *pcVar5) {
LAB_0085c032:
                  iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
                  goto LAB_0085c037;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppppbVar3 + 1);
                bVar7 = bVar1 < (byte)pcVar5[1];
                if (bVar1 != pcVar5[1]) goto LAB_0085c032;
                ppppbVar3 = (byte ****)((int)ppppbVar3 + 2);
                pcVar5 = pcVar5 + 2;
              } while (bVar1 != 0);
              iVar2 = 0;
LAB_0085c037:
              if (iVar2 == 0) {
                ppppbVar3 = (byte ****)local_34[0];
                if (local_20 < 0x10) {
                  ppppbVar3 = local_34;
                }
                pbVar4 = (byte *)((int)ppppbVar3 + 1);
                do {
                  bVar1 = *(byte *)ppppbVar3;
                  ppppbVar3 = (byte ****)((int)ppppbVar3 + 1);
                } while (bVar1 != 0);
                if ((int)ppppbVar3 - (int)pbVar4 == 9) {
                  *(undefined4 *)(in_ECX + 0xc) = 4;
                  goto LAB_0085c0c5;
                }
              }
              ppppbVar3 = (byte ****)local_34[0];
              if (local_20 < 0x10) {
                ppppbVar3 = local_34;
              }
              pcVar5 = "effectstate";
              do {
                bVar1 = *(byte *)ppppbVar3;
                bVar7 = bVar1 < (byte)*pcVar5;
                if (bVar1 != *pcVar5) {
LAB_0085c097:
                  iVar2 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
                  goto LAB_0085c09c;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppppbVar3 + 1);
                bVar7 = bVar1 < (byte)pcVar5[1];
                if (bVar1 != pcVar5[1]) goto LAB_0085c097;
                ppppbVar3 = (byte ****)((int)ppppbVar3 + 2);
                pcVar5 = pcVar5 + 2;
              } while (bVar1 != 0);
              iVar2 = 0;
LAB_0085c09c:
              if (iVar2 == 0) {
                ppppbVar3 = (byte ****)local_34[0];
                if (local_20 < 0x10) {
                  ppppbVar3 = local_34;
                }
                pbVar4 = (byte *)((int)ppppbVar3 + 1);
                do {
                  bVar1 = *(byte *)ppppbVar3;
                  ppppbVar3 = (byte ****)((int)ppppbVar3 + 1);
                } while (bVar1 != 0);
                if ((int)ppppbVar3 - (int)pbVar4 == 0xb) {
                  *(undefined4 *)(in_ECX + 0xc) = 3;
                }
              }
            }
LAB_0085c0c5:
            if (0xf < local_20) {
              FUN_0089120c();
            }
            local_20 = 0xf;
            local_24 = 0;
            local_34[0] = (byte ***)((uint)local_34[0] & 0xffffff00);
            if (0xf < local_3c) {
              FUN_0089120c();
            }
            local_8._0_1_ = 0xff;
            local_8._1_3_ = 0xffffff;
            local_3c = 0xf;
            local_40 = 0;
            local_50[0] = (byte ***)((uint)local_50[0] & 0xffffff00);
            if (0xf < local_58) {
              FUN_0089120c();
            }
          }
        }
      }
      local_90 = local_90 + 1;
    } while (local_90 < local_d4);
  }
  if ((*(int *)(in_ECX + 0x50) != *(int *)(in_ECX + 0x54)) && (*(int *)(in_ECX + 8) != 2)) {
    (**(code **)(**(int **)(in_ECX + 4) + 0xf4))();
    if (local_b4 == 0) {
      OutputDebugStringA("\n G-Blender Warning (gbDxEffect::LoadScript) : No valid technique found")
      ;
    }
    else {
      local_58 = 0xf;
      local_5c = 0;
      local_6c[0] = local_6c[0] & 0xffffff00;
      local_8 = 3;
      FUN_00871ba0();
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_8._0_1_ = 4;
      FUN_00403040(local_6c,0,0xffffffff);
      FUN_0085c4b0(in_ECX);
      if (local_44 == local_40) {
        if (local_44 != 0) {
          FUN_0089120c();
        }
        if (0xf < local_58) {
          FUN_0089120c();
        }
      }
      else {
        FUN_0085f5f0();
        local_8._0_1_ = 5;
        FUN_004fcae0();
        FUN_007cd000();
        local_8._0_1_ = 4;
        if (local_ac != 0) {
          FUN_0089120c();
        }
        (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
        if (local_c4 == 0) {
          if (local_44 != 0) {
            FUN_0089120c();
          }
          if (0xf < local_58) {
            FUN_0089120c();
          }
        }
        else {
          (**(code **)(**(int **)(in_ECX + 4) + 0x38))();
          local_74 = 0xf;
          local_78 = 0;
          local_88[0] = local_88[0] & 0xffffff00;
          local_8._0_1_ = 6;
          FUN_00871d70();
          local_8._0_1_ = 7;
          FUN_00403040(local_88,0,0xffffffff);
          FUN_0085c4b0(in_ECX);
          if (0xf < local_74) {
            FUN_0089120c();
          }
          local_74 = 0xf;
          local_78 = 0;
          local_88[0] = local_88[0] & 0xffffff00;
          if (local_44 != 0) {
            FUN_0089120c();
          }
          if (0xf < local_58) {
            FUN_0089120c();
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

