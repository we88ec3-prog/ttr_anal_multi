
void FUN_007188d0(undefined1 param_1,int param_2)

{
  undefined1 uVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int in_ECX;
  char *in_EDX;
  undefined4 *puVar10;
  undefined4 local_420;
  undefined4 local_41c;
  undefined4 local_418;
  undefined4 local_414;
  int local_410;
  int local_40c;
  char local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x2c) != 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar3 = in_EDX;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  FUN_00402a70(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
  *(undefined1 *)(in_ECX + 0x28) = param_1;
  *(int *)(in_ECX + 0x20) = param_2;
  if (*(int *)(in_ECX + 0x14) == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  iVar7 = *(int *)(in_ECX + 0x24);
  local_408 = '\0';
  if (param_2 == 0) {
    _memset(local_407,0,0x3ff);
    _strcat_s(&local_408,0x400,in_EDX);
    _strcpy_s((char *)&local_40c,4,"rb");
    *(undefined1 *)(iVar7 + 0x210) = param_1;
    iVar4 = FUN_00714770(&local_408,&local_40c);
  }
  else {
    _memset(local_407,0,0x3ff);
    _strcat_s(&local_408,0x400,in_EDX);
    _strcpy_s((char *)&local_410,4,"r+b");
    *(undefined1 *)(iVar7 + 0x210) = param_1;
    iVar4 = FUN_00714770(&local_408,&local_410);
    if (iVar4 != 0) goto LAB_00718a67;
    piVar5 = (int *)FUN_00714770(&local_408,&DAT_00c059a4);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))();
    }
    iVar4 = FUN_00714770(&local_408,&local_410);
  }
  if (iVar4 == 0) {
    *(undefined4 *)(iVar7 + 0xc) = 0;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_00718a67:
  *(int *)(iVar7 + 0xc) = iVar4;
  uVar6 = FUN_00718460();
  uVar1 = *(undefined1 *)(in_ECX + 0x28);
  if ((CONCAT31(CONCAT21(CONCAT11(uVar1,uVar1),uVar1),uVar1) ^ uVar6) == 0x53545044) {
    (**(code **)(*(int **)(in_ECX + 0x24))[1])(&local_414,4);
    (*(code *)**(undefined4 **)(*(int *)(in_ECX + 0x24) + 4))(&local_40c,4);
    *(int *)(in_ECX + 0x44) = local_40c;
    uVar8 = FUN_00718460();
    cVar2 = (**(code **)(**(int **)(in_ECX + 0x24) + 4))();
    if (cVar2 != '\0') {
      (**(code **)**(undefined4 **)(in_ECX + 0x24))();
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    (**(code **)(**(int **)(in_ECX + 0x24) + 0x10))(uVar8,0);
    cVar2 = (**(code **)(**(int **)(in_ECX + 0x24) + 4))();
    if (cVar2 != '\0') {
      (**(code **)**(undefined4 **)(in_ECX + 0x24))(0);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    (*(code *)**(undefined4 **)(*(int *)(in_ECX + 0x24) + 4))(&local_40c,4);
    if (0 < local_40c) {
      local_410 = local_40c;
      puVar10 = *(undefined4 **)(in_ECX + 0x2c);
      do {
        iVar7 = FUN_00891268(0x58);
        if (iVar7 == 0) {
          puVar9 = (undefined4 *)0x0;
        }
        else {
          puVar9 = (undefined4 *)FUN_00717aa0();
        }
        (*(code *)**(undefined4 **)(*(int *)(in_ECX + 0x24) + 4))(&local_41c,4);
        puVar9[0x11] = local_41c;
        (*(code *)**(undefined4 **)(*(int *)(in_ECX + 0x24) + 4))(&local_418,4);
        puVar9[0x13] = local_418;
        (*(code *)**(undefined4 **)(*(int *)(in_ECX + 0x24) + 4))(&local_420,4);
        *puVar9 = local_420;
        (*(code *)**(undefined4 **)(*(int *)(in_ECX + 0x24) + 4))(&local_414,4);
        puVar9[1] = local_414;
        (*(code *)**(undefined4 **)(*(int *)(in_ECX + 0x24) + 4))(puVar9 + 5,0x10);
        puVar9[4] = 1;
        iVar7 = *(int *)(in_ECX + 0x34);
        if (*(int *)(in_ECX + 0x34) <= (int)puVar9[0x11]) {
          iVar7 = puVar9[0x11];
        }
        *(int *)(in_ECX + 0x34) = iVar7;
        if (puVar10 == (undefined4 *)0x0) {
          *(undefined4 **)(in_ECX + 0x30) = puVar9;
          *(undefined4 **)(in_ECX + 0x2c) = puVar9;
        }
        else {
          puVar10[10] = puVar9;
          *(undefined4 **)(in_ECX + 0x30) = puVar9;
          puVar9 = (undefined4 *)puVar10[10];
        }
        local_410 = local_410 + -1;
        puVar10 = puVar9;
      } while (local_410 != 0);
      local_410 = 0;
    }
    if (local_40c != 0) {
      *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + 1;
    }
  }
  else {
    iVar7 = (**(code **)(**(int **)(in_ECX + 0x24) + 0xc))();
    if (iVar7 != 0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x24))(0);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

