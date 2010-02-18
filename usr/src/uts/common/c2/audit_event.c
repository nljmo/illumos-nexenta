 * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.
static au_event_t	aui_fsat(au_event_t);
static au_event_t	aui_execv(au_event_t);
static void	aus_fsat(struct t_audit_data *);
static void	aus_umount(struct t_audit_data *);
static void	aus_xmknod(struct t_audit_data *);
static void	auf_xmknod(struct t_audit_data *, int, rval_t *);
aui_null,	AUE_EXIT,	aus_null,	/* 1 exit */
aui_null,	AUE_FORKALL,	aus_null,	/* 2 forkall */
aui_null,	AUE_NULL,	aus_null,	/* 7 wait */
aui_null,	AUE_CREAT,	aus_null,	/* 8 create */
		auf_null,	S2E_SP,
aui_execv,	AUE_EXEC,	aus_null,	/* 11 exec */
		auf_null,	S2E_MLD,
aui_null,	AUE_UMOUNT,	aus_umount,	/* 22 umount */
aui_null,	AUE_NULL,	aus_null,	/* 26 (loadable) was ptrace */
aui_null,	AUE_UTIME,	aus_null,	/* 30 utime */
aui_null,	AUE_NULL,	aus_null,	/* 41 dup */
aui_null,	AUE_PIPE,	aus_null,	/* 42 pipe */
aui_null,	AUE_NULL,	aus_null,	/* 45 (loadable) */
						/*	was proc lock */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 48 sig */
aui_msgsys,	AUE_MSGSYS,	aus_msgsys,	/* 49 (loadable) was msgsys */
aui_null,	AUE_ACCT,	aus_acct,	/* 51 acct */
aui_shmsys,	AUE_SHMSYS,	aus_shmsys,	/* 52 shared memory */
aui_semsys,	AUE_SEMSYS,	aus_semsys,	/* 53 IPC semaphores */
aui_null,	AUE_NULL,	aus_null,	/* 56 (loadable) was uexch */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 64 (loadable) */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 65 (loadable) */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 66 (loadable) */
aui_null,	AUE_NULL,	aus_null,	/* 67 (loadable) */
						/*	file locking call */
aui_null,	AUE_NULL,	aus_null,	/* 68 (loadable) */
						/*	local system calls */
aui_null,	AUE_NULL,	aus_null,	/* 69 (loadable) inode open */
aui_null,	AUE_NULL,	aus_null,	/* 70 (loadable) was advfs */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 71 (loadable) was unadvfs */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 72 (loadable) was notused */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 73 (loadable) was notused */
		auf_null,	0,
aui_null,	AUE_NULL,	aus_null,	/* 74 (loadable) was notused */
						/*	was sigret (SunOS) */
aui_fsat,	AUE_FSAT,	aus_fsat,	/* 76 fsat */
aui_null,	AUE_NULL,	aus_null,	/* 77 (loadable) was rfstop */
aui_null,	AUE_NULL,	aus_null,	/* 78 (loadable) was rfssys */
						/*	was libattach */
aui_null,	AUE_NULL,	aus_null,	/* 83 (loadable) */
						/*	was libdetach */
aui_null,	AUE_NULL,	aus_null,	/* 87 poll */
aui_null,	AUE_NULL,	aus_null,	/* 101 (loadable) was evsys */
						/*	was evtrapret */
aui_null,	AUE_NULL,	aus_null,	/* 105 (loadable) */
aui_null,	AUE_NULL,	aus_null,	/* 107 waitset */
aui_null,	AUE_NULL,	aus_null,	/* 108 sigsendset */
aui_null,	AUE_NULL,	aus_null,	/* 110 (loadable) was acancel */
aui_null,	AUE_NULL,	aus_null,	/* 111 (loadable) was async */
aui_null,	AUE_PRIOCNTLSYS,	aus_priocntlsys,
		auf_null,	0,		/* 112 priocntlsys */
aui_null,	AUE_STAT,	aus_null,	/* 123 xstat (x86) */
		auf_null,	S2E_PUB,
aui_null,	AUE_LSTAT,	aus_null,	/* 124 lxstat (x86) */
		auf_null,	S2E_PUB,
aui_null,	AUE_NULL,	aus_null,	/* 125 fxstat (x86) */
aui_null,	AUE_MKNOD,	aus_xmknod,	/* 126 xmknod (x86) */
		auf_xmknod,	0,
aui_null,	AUE_NULL,	aus_null,	/* 127 (loadable) was clocal */
aui_null,	AUE_NULL,	aus_null,	/* 140 reserved */
aui_null,	AUE_FORK1,	aus_null,	/* 143 fork1 */
aui_null,	AUE_NULL,	aus_null,	/* 147 lwp_sema_wait */
aui_null,	AUE_NULL,	aus_null,	/* 150 (loadable reserved) */
aui_null,	AUE_NULL,	aus_null,	/* 151 (loadable reserved) */
aui_null,	AUE_UTIMES,	aus_null,	/* 154 utimes */
aui_null,	AUE_NULL,	aus_null,	/* 165 (loadable) */
						/*	was lwp_setprivate */
aui_null,	AUE_NULL,	aus_null,	/* 166 (loadable) */
						/*	was lwp_getprivate */
aui_null,	AUE_NULL,	aus_null,	/* 169 lwp_mutex_lock */
aui_null,	AUE_INST_SYNC,	aus_inst_sync,  /* 176 (loadable) */
						/* aus_inst_sync */
aui_null,	AUE_NULL,	aus_null,	/* 178 (loadable) */
aui_null,	AUE_NULL,	aus_null,	/* 179 (loadable) */
aui_null,	AUE_NULL,	aus_null,	/* 180 (loadable) kaio */
aui_null,	AUE_NULL,	aus_null,	/* 181 (loadable) */
aui_null,	AUE_NULL,	aus_null,	/* 183 (loadable) */
aui_null,	AUE_PROCESSOR_BIND,	aus_processor_bind,
		auf_null,	0,		/* 187 processor_bind */
aui_null,	AUE_NULL,	aus_null,	/* 208 (loadable) */
aui_null,	AUE_NULL,	aus_null,	/* 213 getdents64 (__ppc) */
aui_null,	AUE_CREAT,	aus_null,	/* 224 creat64 */
		auf_null,	S2E_SP,
aui_null,	AUE_NULL,	aus_null,	/* 227 (loadable) */
aui_null,	AUE_NULL,	aus_null,	/* 228 (loadable) */
aui_null,	AUE_NULL,	aus_null,	/* 229 (loadable) */
aui_null,	AUE_NTP_ADJTIME,	aus_null,	/* 249 ntp_adjtime */
/* convert open to appropriate event */
	if (fm & O_WRONLY)
		e = AUE_OPEN_W;
	else if (fm & O_RDWR)
		e = AUE_OPEN_RW;
	else
		e = AUE_OPEN_R;

	if (fm & O_CREAT)
		e += 1;
	if (fm & O_TRUNC)
		e += 2;
	return (e);
/*ARGSUSED*/
	if (!(fm & (O_WRONLY|O_RDWR|O_CREAT|O_TRUNC)))
/* convert openat(2) to appropriate event */
aui_fsat(au_event_t e)
	t_audit_data_t	*tad = U2A(u);
	uint_t fmcode, fm;
		long id;
		long arg1;
		long arg2;
		long arg3;
		long arg4;
		long arg5;
	fmcode  = (uint_t)uap->id;
	switch (fmcode) {
	case 0: /* openat */
	case 1: /* openat64 */
		fm = (uint_t)uap->arg3;
		if (fm & O_WRONLY)
			e = AUE_OPENAT_W;
		else if (fm & O_RDWR)
			e = AUE_OPENAT_RW;
		else
			e = AUE_OPENAT_R;
		/*
		 * openat modes are defined in the following order:
		 * Read only
		 * Read|Create
		 * Read|Trunc
		 * Read|Create|Trunc
		 * Write Only
		 * Write|Create
		 * Write|Trunc
		 * Write|Create|Trunc * RW Only
		 * RW|Create
		 * RW|Trunc
		 * RW|Create|Trunc
		 */
		if (fm & O_CREAT)
			e += 1;		/* increment to include CREAT in mode */
		if (fm & O_TRUNC)
			e += 2;		/* increment to include TRUNC in mode */
		/* convert to appropriate au_ctrl */
		tad->tad_ctrl |= PAD_SAVPATH;
		if (fm & FXATTR)
			tad->tad_ctrl |= PAD_ATPATH;
		break;
	case 2: /* fstatat64 */
	case 3: /* fstatat */
		e = AUE_FSTATAT;
		break;
	case 4: /* fchownat */
		e = AUE_FCHOWNAT;
		break;
	case 5: /* unlinkat */
		e = AUE_UNLINKAT;
		break;
	case 6: /* futimesat */
		e = AUE_FUTIMESAT;
		break;
	case 7: /* renameat */
		e = AUE_RENAMEAT;
		break;
	case 8: /* faccessat */
		e = AUE_FACCESSAT;
		break;
	case 9: /* __openattrdirat */
		tad->tad_ctrl |= PAD_SAVPATH;
		/*FALLTHROUGH*/
	default:
		e = AUE_NULL;
		break;
	}
/*ARGSUSED*/
static void
aus_fsat(struct t_audit_data *tad)
	uint_t fmcode, fm;
		long id;
		long arg1;
		long arg2;
		long arg3;
		long arg4;
		long arg5;
	fmcode  = (uint_t)uap->id;
	switch (fmcode) {

	case 0: /* openat */
	case 1: /* openat64 */
		fm = (uint_t)uap->arg3;
		/* If no write, create, or trunc modes, mark as a public op */
		if (!(fm & (O_WRONLY|O_RDWR|O_CREAT|O_TRUNC)))
			tad->tad_ctrl |= PAD_PUBLIC_EV;

		break;
	case 2: /* fstatat64 */
	case 3: /* fstatat */
		tad->tad_ctrl |= PAD_PUBLIC_EV;
		break;
	default:
		break;
	}
/* null function for now */
static au_event_t
aui_execv(au_event_t e)
{
	return (e);
}

	uint32_t cmd, fd;
	cmd = (uint32_t)uap->cmd;
	fd  = (uint32_t)uap->fd;
/*ARGSUSED*/
static void
aus_xmknod(struct t_audit_data *tad)
{
	klwp_t *clwp = ttolwp(curthread);
	uint32_t fmode;
	dev_t dev;

	struct a {
		long	version;	/* version */
		long	pnamep;		/* char * */
		long	fmode;
		long	dev;
	} *uap = (struct a *)clwp->lwp_ap;

	fmode = (uint32_t)uap->fmode;
	dev   = (dev_t)uap->dev;

	au_uwrite(au_to_arg32(2, "mode", fmode));
#ifdef _LP64
	au_uwrite(au_to_arg64(3, "dev", dev));
#else
	au_uwrite(au_to_arg32(3, "dev", dev));
#endif
}

/*ARGSUSED*/
static void
auf_xmknod(struct t_audit_data *tad, int error, rval_t *rval)
{
	klwp_t *clwp = ttolwp(curthread);
	vnode_t	*dvp;
	caddr_t pnamep;

	struct a {
		long	version;	/* version */
		long	pnamep;		/* char * */
		long	fmode;
		long	dev;
	} *uap = (struct a *)clwp->lwp_arg;


	/* no error, then already path token in audit record */
	if (error != EPERM)
		return;

	/* not auditing this event, nothing then to do */
	if (tad->tad_flag == 0)
		return;

	/* do the lookup to force generation of path token */
	pnamep = (caddr_t)uap->pnamep;
	tad->tad_ctrl |= PAD_NOATTRB;
	error = lookupname(pnamep, UIO_USERSPACE, NO_FOLLOW, &dvp, NULLVPP);
	if (error == 0)
		VN_RELE(dvp);
}

/*
 * the umount syscall is implemented as a call to umount2, but the args
 * are different...
 */

/*ARGSUSED*/
static void
aus_umount(struct t_audit_data *tad)
{
	klwp_t			*clwp = ttolwp(curthread);
	struct a {
		long	dir;		/* char    * */
	} *uap = (struct a *)clwp->lwp_ap;

	aus_umount_path((caddr_t)uap->dir);
}

					au_close(kctx, &(u_ad), 0, 0, 0);
				au_close(kctx, &(u_ad), 0, 0, 0);
			au_close(kctx, &(u_ad), 0, 0, 0);
				au_close(kctx, &(u_ad), 0, 0, 0);
			au_close(kctx, &(u_ad), 0, 0, 0);
				au_close(kctx, &(u_ad), 0, 0, 0);
			au_close(kctx, &(u_ad), 0, 0, 0);
				au_close(kctx, &(u_ad), 0, 0, 0);
			au_close(kctx, &(u_ad), 0, 0, 0);
		au_close(kctx, &(u_ad), 0, 0, 0);
		au_close(kctx, &(u_ad), 0, 0, 0);
		au_close(kctx, &(u_ad), 0, 0, 0);
		au_close(kctx, &(u_ad), 0, 0, 0);
		au_close(kctx, &(u_ad), 0, 0, 0);
		au_close(kctx, &(u_ad), 0, 0, 0);
		au_close(kctx, &(u_ad), 0, 0, 0);
		au_close(kctx, &(u_ad), 0, 0, 0);
		au_close(kctx, &(u_ad), 0, 0, 0);
		au_close(kctx, &(u_ad), 0, 0, 0);