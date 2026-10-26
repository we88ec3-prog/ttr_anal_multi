
void FUN_0086ead0(int *param_1)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  char ****ppppcVar4;
  byte *pbVar5;
  int iVar6;
  int in_ECX;
  byte *pbVar7;
  uint uVar8;
  bool bVar9;
  char *local_260 [3];
  undefined1 local_254 [8];
  uint local_24c;
  int local_244;
  uint local_240;
  int local_23c;
  char ***local_238 [4];
  undefined4 local_228;
  uint local_224;
  byte local_21c [260];
  byte local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917e8b;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x38) != 0) {
    local_23c = in_ECX;
    (**(code **)(*param_1 + 0xc))(param_1,local_254,local_14);
    FUN_0086d5d0();
    local_8 = 0;
    *(undefined4 *)(local_23c + 0x40) = 0;
    local_240 = 0;
    if (local_24c != 0) {
      do {
        uVar8 = local_240;
        local_244 = (**(code **)(*param_1 + 0x30))(param_1,local_240);
        if (local_244 != 0) {
          (**(code **)(*param_1 + 0x14))(param_1,local_244,local_260);
          pcVar3 = local_260[0];
          do {
            cVar1 = *pcVar3;
            pcVar3[(int)(local_21c + -(int)local_260[0])] = cVar1;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          __strlwr((char *)local_21c);
          ppppcVar4 = (char ****)local_238[0];
          if (local_224 < 0x10) {
            ppppcVar4 = local_238;
          }
          iVar6 = -(int)ppppcVar4;
          do {
            bVar2 = *(byte *)ppppcVar4;
            *(byte *)((int)ppppcVar4 + (int)(local_118 + iVar6)) = bVar2;
            ppppcVar4 = (char ****)((int)ppppcVar4 + 1);
          } while (bVar2 != 0);
          __strlwr((char *)local_118);
          pbVar7 = local_118;
          pbVar5 = local_21c;
          do {
            bVar2 = *pbVar5;
            bVar9 = bVar2 < *pbVar7;
            if (bVar2 != *pbVar7) {
LAB_0086ec10:
              iVar6 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
              goto LAB_0086ec15;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar5[1];
            bVar9 = bVar2 < pbVar7[1];
            if (bVar2 != pbVar7[1]) goto LAB_0086ec10;
            pbVar5 = pbVar5 + 2;
            pbVar7 = pbVar7 + 2;
          } while (bVar2 != 0);
          iVar6 = 0;
LAB_0086ec15:
          if (iVar6 == 0) {
            pbVar7 = local_21c;
            do {
              bVar2 = *pbVar7;
              pbVar7 = pbVar7 + 1;
            } while (bVar2 != 0);
            pbVar5 = local_118;
            do {
              bVar2 = *pbVar5;
              pbVar5 = pbVar5 + 1;
            } while (bVar2 != 0);
            uVar8 = local_240;
            if ((int)pbVar7 - (int)(local_21c + 1) == (int)pbVar5 - (int)(local_118 + 1)) {
              *(int *)(local_23c + 0x40) = local_244;
              break;
            }
          }
        }
        local_240 = uVar8 + 1;
      } while (local_240 < local_24c);
    }
    local_8 = 0xffffffff;
    if (0xf < local_224) {
      FUN_0089120c(local_238[0]);
    }
    local_224 = 0xf;
    local_228 = 0;
    local_238[0] = (char ***)((uint)local_238[0] & 0xffffff00);
    in_ECX = local_23c;
  }
  if (*(int *)(in_ECX + 0x40) == 0) {
    OutputDebugStringA("G-Blender Effect Warning : Null Technique\n");
  }
  else {
    (**(code **)(*param_1 + 0xe8))(param_1,*(int *)(in_ECX + 0x40));
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

