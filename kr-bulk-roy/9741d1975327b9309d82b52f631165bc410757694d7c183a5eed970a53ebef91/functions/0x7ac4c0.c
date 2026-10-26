
/* WARNING: Type propagation algorithm not settling */

void FUN_007ac4c0(undefined4 param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  char *******pppppppcVar6;
  char *******pppppppcVar7;
  undefined4 *puVar8;
  LPCSTR ******lpText;
  int *in_ECX;
  char *in_EDX;
  undefined1 local_13c [7];
  char local_135;
  undefined4 local_134;
  undefined4 local_130;
  undefined1 local_6c;
  uint local_68;
  undefined4 local_58;
  uint local_54;
  LPCSTR ******local_4c [4];
  undefined4 local_3c;
  uint local_38;
  char *******local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009354c1;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (char *******)((uint)local_30[0] & 0xffffff00);
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70(param_2,(int)pcVar3 - (int)(param_2 + 1));
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  pcVar3 = in_EDX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
  pppppppcVar6 = local_30[0];
  if (local_1c < 0x10) {
    pppppppcVar6 = (char *******)local_30;
  }
  piVar4 = (int *)FUN_00714770(pppppppcVar6,&DAT_00bed1e0,uVar2);
  if (piVar4 == (int *)0x0) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c[0] = (LPCSTR ******)((uint)local_4c[0] & 0xffffff00);
    pcVar3 = in_EDX;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
    local_8._0_1_ = 4;
    FUN_00401fc0(&DAT_00c4f820,0x18);
    lpText = local_4c[0];
    if (local_38 < 0x10) {
      lpText = (LPCSTR ******)local_4c;
    }
    MessageBoxA((HWND)0x0,(LPCSTR)lpText,"Error",0);
    if (0xf < local_38) {
      FUN_0089120c(local_4c[0]);
    }
  }
  else {
    (**(code **)(*piVar4 + 0x10))(local_13c,1,2);
    (**(code **)(*piVar4 + 0x34))(0,0);
    (**(code **)(*piVar4 + 4))();
    if (*in_ECX == 0) {
      iVar5 = FUN_00891268(0xf8);
      local_8._0_1_ = 1;
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_007c3220(iVar5);
      }
      local_8._0_1_ = 0;
      *in_ECX = iVar5;
    }
    if (((char)local_13c._0_2_ == '<') ||
       (((char)local_13c._0_2_ == 'E' && (SUB21(local_13c._0_2_,1) == 'X')))) {
      local_134 = 0;
      local_130 = 0;
      FUN_0071bc20();
      local_6c = 0;
      local_54 = 0xf;
      local_58 = 0;
      local_68 = local_68 & 0xffffff00;
      local_8._0_1_ = 2;
      pppppppcVar6 = local_30[0];
      if (local_1c < 0x10) {
        pppppppcVar6 = (char *******)local_30;
      }
      local_38 = 0xf;
      local_3c = 0;
      local_4c[0] = (LPCSTR ******)((uint)local_4c[0] & 0xffffff00);
      pppppppcVar7 = pppppppcVar6;
      do {
        cVar1 = *(char *)pppppppcVar7;
        pppppppcVar7 = (char *******)((int)pppppppcVar7 + 1);
      } while (cVar1 != '\0');
      FUN_00402a70(pppppppcVar6,(int)pppppppcVar7 - (int)((int)pppppppcVar6 + 1));
      local_8._0_1_ = 3;
      local_135 = FUN_00498e50(&local_134);
      local_8 = CONCAT31(local_8._1_3_,2);
      if (0xf < local_38) {
        FUN_0089120c(local_4c[0]);
      }
      if (local_135 != '\0') {
        puVar8 = (undefined4 *)FUN_0071ba40("CharacterList");
        FUN_007aee60(param_1,param_2,*puVar8);
      }
      local_8._0_1_ = 0;
      if (0xf < local_54) {
        FUN_0089120c(local_68);
      }
      local_54 = 0xf;
      local_58 = 0;
      local_68 = local_68 & 0xffffff00;
      FUN_0071bc90(&local_134);
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      goto LAB_007ac7b8;
    }
    pppppppcVar6 = local_30[0];
    if (local_1c < 0x10) {
      pppppppcVar6 = (char *******)local_30;
    }
    MessageBoxA((HWND)0x0,&DAT_00c4f7c0,(LPCSTR)pppppppcVar6,0);
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
LAB_007ac7b8:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

