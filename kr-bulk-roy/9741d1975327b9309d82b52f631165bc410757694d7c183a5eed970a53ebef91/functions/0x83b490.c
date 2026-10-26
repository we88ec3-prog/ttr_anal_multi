
void FUN_0083b490(LPCSTR param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  LPCSTR *****lpPathName;
  int iVar7;
  LPCSTR lpOutputString;
  undefined4 *puVar8;
  int *piVar9;
  int in_ECX;
  undefined *puVar10;
  int *local_550;
  char *local_54c;
  int *local_548;
  LPCSTR ****local_544 [4];
  undefined4 local_534;
  uint local_530;
  CHAR local_528 [1300];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093201b;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_548 = (int *)0x0;
  local_550 = (int *)0x0;
  local_54c = param_2;
  local_530 = 0xf;
  local_534 = 0;
  local_544[0] = (LPCSTR ****)((uint)local_544[0] & 0xffffff00);
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_2,(int)pcVar3 - (int)(param_2 + 1));
  local_8 = 0;
  uVar4 = FUN_0083eff0(&DAT_00c420d4,1);
  uVar5 = FUN_0083eff0(&DAT_00bed1e4,1);
  if (uVar4 < uVar5) {
    puVar10 = &DAT_00bed1e4;
  }
  else {
    puVar10 = &DAT_00c420d4;
  }
  iVar6 = FUN_0083eff0(puVar10,1);
  pcVar3 = local_54c;
  if (iVar6 != -1) {
    GetCurrentDirectoryA(0x514,local_528);
    FUN_00402c80(iVar6,local_534);
    lpPathName = (LPCSTR *****)local_544[0];
    if (local_530 < 0x10) {
      lpPathName = local_544;
    }
    SetCurrentDirectoryA((LPCSTR)lpPathName);
    pcVar3 = param_2 + iVar6 + 1;
  }
  iVar7 = D3DXCreateEffectFromFileA
                    (*(undefined4 *)(in_ECX + 0xec),pcVar3,0,0,0x805,*(undefined4 *)(in_ECX + 0x3f0)
                     ,&local_548,&local_550);
  if (iVar6 != -1) {
    SetCurrentDirectoryA(local_528);
  }
  if (iVar7 == 0) {
    local_54c = (char *)0x0;
    (**(code **)(*local_548 + 0xf4))(local_548,0,&local_54c);
    if (local_54c == (char *)0x0) {
      (**(code **)(*local_548 + 8))(local_548);
      OutputDebugStringA(&DAT_00c53e10);
      OutputDebugStringA(param_1);
      OutputDebugStringA("\n");
    }
    else {
      puVar8 = (undefined4 *)FUN_00863c20(in_ECX + 0x134,param_1,local_548);
      uVar2 = *puVar8;
      *param_3 = uVar2;
      iVar6 = FUN_0083ff20(in_ECX + 0x144,uVar2);
      (**(code **)(*local_548 + 8))(local_548);
      if ((*(int *)(iVar6 + 8) == 2) &&
         (iVar6 = *(int *)(in_ECX + 0x418),
         piVar9 = (int *)FUN_008402e0(*(undefined4 *)(in_ECX + 0x414),iVar6,param_3),
         *piVar9 == iVar6)) {
        FUN_0083eab0();
      }
      OutputDebugStringA(&DAT_00c53dec);
      OutputDebugStringA(param_1);
      OutputDebugStringA("\n");
    }
    if (0xf < local_530) {
      FUN_0089120c(local_544[0]);
    }
  }
  else {
    if ((local_550 != (int *)0x0) && (local_548 == (int *)0x0)) {
      OutputDebugStringA("G-BLENDER : ");
      lpOutputString = (LPCSTR)(**(code **)(*local_550 + 0xc))(local_550);
      OutputDebugStringA(lpOutputString);
      OutputDebugStringA("\n");
      (**(code **)(*local_550 + 8))(local_550);
    }
    if (0xf < local_530) {
      FUN_0089120c(local_544[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

