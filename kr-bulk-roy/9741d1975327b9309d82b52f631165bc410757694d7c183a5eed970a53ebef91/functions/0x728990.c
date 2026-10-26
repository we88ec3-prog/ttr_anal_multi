
void FUN_00728990(char *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  void *pvVar6;
  int *piVar7;
  FILE *_File;
  long lVar8;
  char *in_ECX;
  int local_68;
  char *local_64;
  uint *local_60;
  undefined4 local_5c;
  uint local_58 [20];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_60 = local_58;
  local_68 = -1;
  local_5c = 0;
  local_64 = param_1;
  if ((in_ECX == (char *)0x0) || (param_1 == (char *)0x0)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  puVar2 = _malloc(0x74);
  if (puVar2 == (undefined4 *)0x0) goto LAB_00728b00;
  puVar2[8] = 0;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0x11] = 0;
  *puVar2 = 0;
  puVar2[0x12] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[1] = 0;
  puVar2[0x10] = 0;
  puVar2[0xe] = 0;
  puVar2[0xf] = 0;
  puVar2[0x19] = 0;
  puVar2[0x1a] = 0;
  puVar2[0x1b] = 0xffffffff;
  puVar2[0x13] = 0;
  puVar2[0x14] = 0;
  puVar2[0x16] = 0;
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar4 = _malloc((size_t)(pcVar3 + (1 - (int)(in_ECX + 1))));
  puVar2[0x15] = pcVar4;
  pcVar3 = in_ECX;
  if (pcVar4 != (char *)0x0) {
    do {
      cVar1 = *pcVar3;
      *pcVar4 = cVar1;
      pcVar4 = pcVar4 + 1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    *(undefined1 *)(puVar2 + 0x17) = 0;
    do {
      if (*local_64 == 'r') {
        *(undefined1 *)(puVar2 + 0x17) = 0x72;
      }
      if ((*local_64 == 'w') || (*local_64 == 'a')) {
        *(undefined1 *)(puVar2 + 0x17) = 0x77;
      }
      cVar1 = *local_64;
      if ((cVar1 < '0') || ('9' < cVar1)) {
        if (cVar1 == 'f') {
          local_5c = 1;
        }
        else if (cVar1 == 'h') {
          local_5c = 2;
        }
        else if (cVar1 == 'R') {
          local_5c = 3;
        }
        else {
          *(char *)local_60 = cVar1;
          local_60 = (uint *)((int)local_60 + 1);
        }
      }
      else {
        local_68 = cVar1 + -0x30;
      }
      local_64 = local_64 + 1;
    } while ((cVar1 != '\0') && (local_60 != &local_8));
    if (*(char *)(puVar2 + 0x17) != '\0') {
      if (*(char *)(puVar2 + 0x17) == 'w') {
        iVar5 = FUN_00729760(local_68,0xfffffff1,local_5c);
        pvVar6 = _malloc(0x4000);
        puVar2[0x12] = pvVar6;
        puVar2[3] = pvVar6;
        if (iVar5 == 0) {
joined_r0x00728b36:
          if (pvVar6 != (void *)0x0) {
            puVar2[4] = 0x4000;
            piVar7 = __errno();
            *piVar7 = 0;
            _File = _fopen(in_ECX,(char *)local_58);
            puVar2[0x10] = _File;
            if (_File != (FILE *)0x0) {
              if (*(char *)(puVar2 + 0x17) != 'w') {
                FUN_00728c50();
                lVar8 = _ftell((FILE *)puVar2[0x10]);
                puVar2[0x18] = lVar8 - puVar2[1];
                __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
                return;
              }
              _fprintf(_File,"%c%c%c%c%c%c%c%c%c%c",0x1f,0x8b,8,0,0,0,0,0,0,0xb);
              puVar2[0x18] = 10;
              __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
              return;
            }
          }
        }
      }
      else {
        pvVar6 = _malloc(0x4000);
        puVar2[0x11] = pvVar6;
        *puVar2 = pvVar6;
        iVar5 = FUN_00727310();
        if (iVar5 == 0) {
          pvVar6 = (void *)puVar2[0x11];
          goto joined_r0x00728b36;
        }
      }
    }
  }
  FUN_00728db0();
LAB_00728b00:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

