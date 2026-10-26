
void FUN_008d49c0(void)

{
  char *pcVar1;
  char cVar2;
  uint _Size;
  int iVar3;
  char *pcVar4;
  undefined1 *_Dst;
  uint uVar5;
  int in_ECX;
  uint uVar6;
  char *local_2c [4];
  uint local_1c [5];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_1c[0] = 0;
  local_2c[0] = (char *)0x0;
  local_2c[1] = (undefined1 *)0x0;
  local_2c[2] = (char *)0x0;
  local_2c[3] = (char *)0x0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  iVar3 = FUN_008d3fa0("SLANT");
  if (((iVar3 != 0) && (*(char *)(iVar3 + 4) != '\0')) &&
     ((cVar2 = **(char **)(iVar3 + 8), cVar2 == 'O' ||
      (((cVar2 == 'o' || (cVar2 == 'I')) || (cVar2 == 'i')))))) {
    *(undefined4 *)(in_ECX + 0xc) = 1;
    if ((**(char **)(iVar3 + 8) == 'O') || (local_2c[2] = "Italic", **(char **)(iVar3 + 8) == 'o'))
    {
      local_2c[2] = "Oblique";
    }
  }
  iVar3 = FUN_008d3fa0("WEIGHT_NAME");
  if (((iVar3 != 0) && (*(char *)(iVar3 + 4) != '\0')) &&
     ((**(char **)(iVar3 + 8) == 'B' || (**(char **)(iVar3 + 8) == 'b')))) {
    *(uint *)(in_ECX + 0xc) = *(uint *)(in_ECX + 0xc) | 2;
    local_2c[1] = "Bold";
  }
  iVar3 = FUN_008d3fa0("SETWIDTH_NAME");
  if ((iVar3 != 0) && (*(char *)(iVar3 + 4) != '\0')) {
    cVar2 = **(char **)(iVar3 + 8);
    if ((cVar2 != '\0') && ((cVar2 != 'N' && (cVar2 != 'n')))) {
      local_2c[3] = *(char **)(iVar3 + 8);
    }
  }
  iVar3 = FUN_008d3fa0("ADD_STYLE_NAME");
  if ((iVar3 != 0) && (*(char *)(iVar3 + 4) != '\0')) {
    cVar2 = **(char **)(iVar3 + 8);
    if ((cVar2 != '\0') && ((cVar2 != 'N' && (cVar2 != 'n')))) {
      local_2c[0] = *(char **)(iVar3 + 8);
    }
  }
  iVar3 = 0;
  uVar6 = 0;
  do {
    pcVar4 = *(char **)((int)local_2c + uVar6);
    *(undefined4 *)((int)local_1c + uVar6 + 4) = 0;
    if (pcVar4 != (char *)0x0) {
      pcVar1 = pcVar4 + 1;
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      *(int *)((int)local_1c + uVar6 + 4) = (int)pcVar4 - (int)pcVar1;
      iVar3 = iVar3 + 1 + ((int)pcVar4 - (int)pcVar1);
    }
    uVar6 = uVar6 + 4;
  } while (uVar6 < 0x10);
  if (iVar3 == 0) {
    local_2c[0] = "Regular";
    local_1c[1] = 7;
    iVar3 = 8;
  }
  _Dst = (undefined1 *)FUN_008baee0(*(undefined4 *)(in_ECX + 100),iVar3,local_1c);
  *(undefined1 **)(in_ECX + 0x18) = _Dst;
  if (local_1c[0] != 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  uVar6 = 0;
  do {
    pcVar4 = local_2c[uVar6];
    _Size = local_1c[uVar6 + 1];
    if (pcVar4 != (char *)0x0) {
      if (_Dst != *(undefined1 **)(in_ECX + 0x18)) {
        *_Dst = 0x20;
        _Dst = _Dst + 1;
      }
      FID_conflict__memcpy(_Dst,pcVar4,_Size);
      if (((uVar6 == 0) || (uVar6 == 3)) && (uVar5 = 0, _Size != 0)) {
        do {
          if (_Dst[uVar5] == ' ') {
            _Dst[uVar5] = 0x2d;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < _Size);
      }
      _Dst = _Dst + _Size;
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 4);
  *_Dst = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

