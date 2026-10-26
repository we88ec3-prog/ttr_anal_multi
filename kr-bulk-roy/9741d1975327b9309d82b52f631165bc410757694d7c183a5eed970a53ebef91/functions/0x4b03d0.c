
void FUN_004b03d0(int param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  byte bVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined4 ***pppuVar11;
  int local_5c;
  int local_54;
  uint local_44;
  uint local_40;
  undefined4 **local_3c [4];
  undefined4 local_2c;
  uint local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00936de4;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_2 < 2) {
    local_44 = 0;
  }
  else {
    local_44 = (param_2 - 2) / 0x11;
  }
  local_14 = uVar6;
  if (local_44 != 0) {
    puVar10 = (undefined4 *)(param_1 + 5);
    do {
      local_40 = (uint)*(ushort *)((int)puVar10 + -3);
      iVar7 = FUN_0040f060(uVar6);
      FUN_0082ef00(&local_40);
      if ((local_5c == *(int *)(iVar7 + 0xc)) || (iVar7 = *(int *)(local_5c + 0x10), iVar7 == 0)) {
        FUN_006edb60("Error [USE_SKILL]: cannot found In CharList");
      }
      else {
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_8 = 0;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          local_8 = 0xffffffff;
        }
        local_40 = (uint)*(ushort *)(puVar10 + 2);
        FUN_0047fdf0(&local_40);
        if (local_54 == DAT_00fb7524) {
          pcVar9 = "";
        }
        else {
          pcVar9 = (char *)(local_54 + 0x10);
          if (0xf < *(uint *)(local_54 + 0x24)) {
            pcVar9 = *(char **)pcVar9;
          }
        }
        local_28 = 0xf;
        local_2c = 0;
        local_3c[0] = (undefined4 **)((uint)local_3c[0] & 0xffffff00);
        pcVar8 = pcVar9;
        do {
          cVar3 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar3 != '\0');
        FUN_00402a70(pcVar9,(int)pcVar8 - (int)(pcVar9 + 1));
        local_8 = 1;
        local_20 = *puVar10;
        local_1c = puVar10[1];
        local_18 = 0;
        (**(code **)*DAT_00fba838)(local_20,local_1c,&local_18,0);
        uVar1 = *(undefined4 *)(iVar7 + 0xb4);
        bVar4 = *(byte *)((int)puVar10 + -1);
        if ((DAT_00fb7c18 & 1) == 0) {
          DAT_00fb7c18 = DAT_00fb7c18 | 1;
          FUN_004449d0();
        }
        uVar2 = (&DAT_00fb7c20)[bVar4];
        pppuVar11 = (undefined4 ***)local_3c[0];
        if (local_28 < 0x10) {
          pppuVar11 = local_3c;
        }
        if ((DAT_00fdf6dc & 1) == 0) {
          DAT_00fdf6dc = DAT_00fdf6dc | 1;
          local_8._0_1_ = 2;
          FUN_00550820();
          _atexit((_func_4879 *)&LAB_00bce6b0);
          local_8 = CONCAT31(local_8._1_3_,1);
        }
        uVar5 = *(undefined2 *)((int)puVar10 + -3);
        if (pppuVar11 != (undefined4 ***)0x0) {
          FUN_00551cd0();
        }
        FUN_00551dd0(&DAT_00fdf680,uVar5,&local_20,uVar2,uVar1,1);
        local_8 = 0xffffffff;
        if (0xf < local_28) {
          FUN_0089120c(local_3c[0]);
        }
      }
      puVar10 = (undefined4 *)((int)puVar10 + 0x11);
      local_44 = local_44 - 1;
    } while (local_44 != 0);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

