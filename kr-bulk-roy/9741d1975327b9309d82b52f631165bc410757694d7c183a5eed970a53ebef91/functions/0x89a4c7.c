
/* Library Function - Single Match
    _system
   
   Library: Visual Studio 2010 Release */

int __cdecl _system(char *_Command)

{
  int iVar1;
  errno_t eVar2;
  int *piVar3;
  uint uVar4;
  char *local_18;
  undefined *local_14;
  char *local_10;
  undefined4 local_c;
  char *local_8;
  
  local_8 = (char *)0x0;
  uVar4 = 0;
  eVar2 = __dupenv_s(&local_8,(size_t *)0x0,"COMSPEC");
  if ((eVar2 != 0) && (eVar2 == 0x16)) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  local_18 = local_8;
  if (_Command == (char *)0x0) {
    if (local_8 != (char *)0x0) {
      eVar2 = __access_s(local_8,0);
      uVar4 = (uint)(eVar2 == 0);
    }
    goto LAB_0089a595;
  }
  local_14 = &DAT_00bd3b58;
  local_10 = _Command;
  local_c = 0;
  if (local_8 != (char *)0x0) {
    piVar3 = __errno();
    iVar1 = *piVar3;
    piVar3 = __errno();
    *piVar3 = 0;
    uVar4 = __spawnve(0,local_18,&local_18,(char **)0x0);
    piVar3 = __errno();
    if (uVar4 != 0xffffffff) {
      *piVar3 = iVar1;
      goto LAB_0089a595;
    }
    if ((*piVar3 != 2) && (piVar3 = __errno(), *piVar3 != 0xd)) goto LAB_0089a595;
    piVar3 = __errno();
    *piVar3 = iVar1;
  }
  local_18 = "cmd.exe";
  uVar4 = __spawnvpe(0,"cmd.exe",&local_18,(char **)0x0);
LAB_0089a595:
  _free(local_8);
  return uVar4;
}

