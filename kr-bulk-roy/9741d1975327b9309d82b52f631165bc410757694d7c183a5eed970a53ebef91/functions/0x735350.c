
void FUN_00735350(int param_1)

{
  LPRECT lprc;
  int iVar1;
  undefined4 *unaff_ESI;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (((unaff_ESI != (undefined4 *)0x0) && (*(int *)(param_1 + 0x2c) != 0x400)) &&
     (unaff_ESI[5] != 0)) {
    lprc = (LPRECT)(unaff_ESI + 9);
    SetRect(lprc,0,0,0,0);
    local_1c = lprc->left;
    local_18 = unaff_ESI[10];
    local_14 = unaff_ESI[0xb];
    local_10 = unaff_ESI[0xc];
    local_20 = (int)(unaff_ESI + 1);
    if (7 < (uint)unaff_ESI[6]) {
      local_20 = *(int *)local_20;
    }
    (**(code **)(**(int **)(param_1 + 8) + 0x48))(*unaff_ESI,local_20,unaff_ESI[8],&local_1c);
    if ((local_14 != local_1c) && (local_10 != local_18)) {
      if ((local_14 - local_1c < 0) || (local_10 - local_18 < 0)) {
        DebugBreak();
      }
      else {
        iVar1 = FUN_00734ad0(*(undefined4 *)(param_1 + 0x38),&local_24);
        if (iVar1 != 0) {
          lprc->left = local_24 + local_1c;
          unaff_ESI[10] = local_18 + local_20;
          unaff_ESI[0xb] = local_24 + local_14;
          iVar1 = local_20 + local_10;
          local_20 = (int)(unaff_ESI + 1);
          unaff_ESI[0xc] = iVar1;
          if (7 < (uint)unaff_ESI[6]) {
            local_20 = *(int *)local_20;
          }
          (**(code **)(**(int **)(param_1 + 8) + 0x30))(*unaff_ESI,local_20,unaff_ESI[8],&local_1c);
          (**(code **)(**(int **)(param_1 + 8) + 0x34))(*(undefined4 *)(param_1 + 4),&local_1c,lprc)
          ;
          FUN_00736400(&local_24,&stack0xffffffd8);
          __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
          return;
        }
      }
    }
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

