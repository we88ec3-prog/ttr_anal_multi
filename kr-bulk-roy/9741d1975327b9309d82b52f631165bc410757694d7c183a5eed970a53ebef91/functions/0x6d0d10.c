
void FUN_006d0d10(void)

{
  FILE **ppFVar1;
  FILE **ppFVar2;
  FILE *pFVar3;
  char *pcVar4;
  int iVar5;
  int local_118;
  FILE *local_114;
  FILE *local_110 [2];
  char local_108;
  undefined1 local_107 [255];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_110[1] = (FILE *)0x0;
  _fopen_s(local_110 + 1,"Virualkey.dll","rb");
  if (local_110[1] != (FILE *)0x0) {
    FUN_006d0700();
    local_118 = 0;
    local_114 = (FILE *)0x0;
    local_108 = '\0';
    _memset(local_107,0,0xff);
    pcVar4 = _fgets(&local_108,0xff,local_110[1]);
    while (pcVar4 != (char *)0x0) {
      iVar5 = FID_conflict__sscanf(&local_108,"%d %d",&local_118,&local_114);
      pFVar3 = local_114;
      if (iVar5 == 2) {
        iVar5 = local_118 * 0x10;
        ppFVar1 = *(FILE ***)(&DAT_00fb8d38 + iVar5);
        local_110[0] = local_114;
        if (local_110 < ppFVar1) {
          ppFVar2 = *(FILE ***)(&DAT_00fb8d34 + iVar5);
          if (local_110 < ppFVar2) goto LAB_006d0e33;
          if (ppFVar1 == *(FILE ***)(&DAT_00fb8d3c + iVar5)) {
            FUN_006d6240();
          }
          if (*(undefined4 **)(&DAT_00fb8d38 + iVar5) != (undefined4 *)0x0) {
            **(undefined4 **)(&DAT_00fb8d38 + iVar5) =
                 *(undefined4 *)
                  (*(uint *)(&DAT_00fb8d34 + iVar5) + ((int)local_110 - (int)ppFVar2 >> 2) * 4);
          }
        }
        else {
LAB_006d0e33:
          if (ppFVar1 == *(FILE ***)(&DAT_00fb8d3c + iVar5)) {
            FUN_006d6240();
          }
          if (*(undefined4 **)(&DAT_00fb8d38 + iVar5) != (undefined4 *)0x0) {
            **(undefined4 **)(&DAT_00fb8d38 + iVar5) = pFVar3;
          }
        }
        *(int *)(&DAT_00fb8d38 + iVar5) = *(int *)(&DAT_00fb8d38 + iVar5) + 4;
      }
      _memset(&local_108,0,0x100);
      pcVar4 = _fgets(&local_108,0xff,local_110[1]);
    }
    _fclose(local_110[1]);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

